#define _CRT_SECURE_NO_WARNINGS
#include <QCoreApplication>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <iostream>
#include <string>   // для stoi и to_string
#include "httplib.h"
#include <fstream>
#include <curl/curl.h>
#include "sites.h"
#include "json.hpp"
#include <chrono>
using json = nlohmann::json;
using namespace httplib;

std::string ReturnTime()
{
    std::string line;
    // Получаем текущее время
    auto now = std::chrono::system_clock::now();

    // Преобразуем время в местное время
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&now_time);

    // Извлекаем нужные компоненты времени
    int day = local_tm.tm_mday;        // День месяца (от 1 до 31)
    int month = local_tm.tm_mon + 1;   // Месяц (от 0 до 11, поэтому добавляем 1)
    int year = local_tm.tm_year + 1900; // Год (текущий год + 1900)
    line += std::to_string(day) + R"###(/)###" + std::to_string(month) + R"###(/)###" + std::to_string(year);
    return line;
}

void Rawer(std::string& link)
{

    for(int i = 0; i < 4; i++)
    {
        link.pop_back();
    }
    link += "raw=1";
}

mongocxx::collection collection;

void PrintLog(std::string log)
{
    std::cout<<'\n'<<log<<'\n';
}

void PrintArr(std::vector<std::vector<std::string>>& arrinarr)
{
    for(const auto& arr : arrinarr)
    {
        for(const auto& str : arr)
        {
            PrintLog(str);
        }
    }
}

namespace hide
{
    enum class ChangeStatus
    {
        Hadsite,
        Myhadsite
    };
    std::string price;

    std::string login = "guest";
    std::string password;

    std::string lastProductname;
    std::string lastProductdeskription;
    std::string pictyre = "no_pyctyre";

    int page = 0;
    int maxpage = 0;
    ChangeStatus status = ChangeStatus::Hadsite;

    std::vector<std::vector<std::string>> commentsArray = {{"1", "2", "3"}, {"1", "2", "3"}, {"1", "2", "3"}};
}

std::vector<std::vector<std::string>> DimensionsOfVector(std::vector<std::vector<std::string>>& comments)
{
    std::vector<std::vector<std::string>> returnvec;
    std::vector<std::string> coment = {"nothin1", "nothin2", "nothin3"};

    returnvec = comments;

    if(comments.size() < 3)
    {
        std::cout<<comments.size();

        for(auto i = comments.size(); i < 3; i++)
        {
            returnvec.push_back(coment);
        }


    }
    else if (comments.size() > 3)
    {
        auto beg = comments.cbegin();
        auto end = comments.cend();
        comments.erase(beg, end - 3);
        returnvec = comments;
    }
    return returnvec;
}

std::string Cleaner(std::string line)
{
    std::string line1;

    for(char& sign : line)
    {
        if(sign != '"')
        {
            line1.push_back(sign);
        }
    }
    return line1;
}

void handlerAddproductSite(const Request& req, Response& res)
{
    auto productName = req.has_param("productName") ? req.get_param_value("productName") : "no_name";
    auto description = req.has_param("description") ? req.get_param_value("description") : "no_deskription";

    res.set_content(AddProductSite(), "text/html");
}

void handlerPersonalArea(const Request& req, Response& res)
{

    std::string name;
    std::string description;
    std::string picture;
    std::vector<std::vector<std::string>> comments;

    name = hide::login;

    auto person = bsoncxx::from_json(R"###({"salesman":")###" + name + R"###(", "type": "salesman"})###");
    auto cursor = collection.find_one(person.view());

    if(cursor)
    {
        auto doc = cursor->view();
        std::string line = bsoncxx::to_json(doc);
        json document = json::parse(line);

        description = Cleaner(document["description"]);
        picture = Cleaner(document["picture"]);

        for(const auto& item : document["comments"])
        {
            std::vector<std::string> inner_vector;
            for(const auto& inner_item : item)
            {
                inner_vector.push_back(Cleaner(inner_item.get<std::string>()));
            }
            comments.push_back(inner_vector);
        }
    }
    PrintArr(comments);

    res.set_content(PersonalArea(name, description, picture, comments), "text/html");
}
// do it
void PublicProduct(const Request& req, Response& res)
{
    std::string salesman = hide::login;
    // auto salesman = req.has_param("salesman") ? req.get_param_value("salesman") : "no_name";
    auto productName = req.has_param("productname") ? req.get_param_value("productname") : "no_product";
    auto description = req.has_param("productdescription") ? req.get_param_value("productdescription") : "no_deskription";
    auto price = req.has_param("price") ? req.get_param_value("price") : "free";


    hide::lastProductname = productName;
    hide::lastProductdeskription = description;
    std::string pictyre = hide::pictyre;

    std::string product = R"###({"type":"product",
                                "productName":")###" + productName + R"###(",
                            "productDeskription":")###" + description + R"###(",
                            "salesman":")###" + salesman + R"###(",
                            "basket":[],
                            "price":")###" + price + R"###(",
                            "status":"on_sale",
                            "picture":")###" + pictyre + R"###(",
                            "comments":[["","",""], ["","",""], ["","",""]]})###";

    auto doc = bsoncxx::from_json(product);
    collection.insert_one(doc.view());


    handlerPersonalArea(req, res);
}

void PublicUser(const Request& req, Response& res)
{
    auto salesman = req.has_param("login") ? req.get_param_value("login") : "no_login";
    auto password = req.has_param("password") ? req.get_param_value("password") : "no_password";
    auto description = req.has_param("description") ? req.get_param_value("description") : "no_description";
    std::string picture = hide::pictyre;

    std::string product = R"###({"type":"salesman",
                                "salesman":")###" + salesman + R"###(",
                            "password":")###" + password + R"###(",
                            "description":")###" + description + R"###(",
                            "picture":")###" + picture + R"###(",
                            "comments":[["","",""], ["","",""], ["","",""]]})###";

    auto doc = bsoncxx::from_json(product);
    collection.insert_one(doc.view());

    res.set_content(LogIn(), "text/html");
}

void ParseProduct(std::vector<std::string>& products, std::vector<std::string>& descriptions, std::vector<std::string>& pictyres, mongocxx::cursor& cursor)
{
    for (auto&& doc : cursor) {
        std::string doc_str = bsoncxx::to_json(doc);
        json doc_json = json::parse(doc_str);

        // Обработка возможных исключений при доступе к ключам
        try {
            std::string productName = doc_json.at("productName").get<std::string>();
            std::string productDescription = doc_json.at("productDeskription").get<std::string>();
            std::string pictyre = doc_json.at("picture").get<std::string>();

            //std::cout << productName << std::endl;
            //std::cout << productDescription << std::endl;

            products.push_back(productName);
            descriptions.push_back(productDescription);
            pictyres.push_back(pictyre);

        } catch (json::exception& e) {
            std::cerr << "Error accessing key: " << e.what() << std::endl;
        }
    }

}

// срочно оптимизировать двойной сбор данных с базы (вынести парсер)
std::vector<std::vector<std::string>> GetProducts(int count, int page = 0, std::string salesman = "no_name")
{
    // 3 = for salesman
    std::vector<std::vector<std::string>> fullvector;
    std::vector<std::string> products;
    std::vector<std::string> descriptions;
    std::vector<std::string> pictures;


    std::cout<<salesman;
    auto allproduct = bsoncxx::from_json(R"###({"type":"product", "status": "on_sale"})###");

    if (count == 3)
    {
        PrintLog("on geting my products with " + hide::login);
        allproduct = bsoncxx::from_json(R"###({"type":"product", "salesman":")###" + salesman + R"###(", "status": "on_sale"})###");
    }
    else if (count == 4)
    {
        PrintLog("on geting to basket " + hide::login);
        allproduct = bsoncxx::from_json(R"###({"basket": ")###" + salesman + R"###(", "status": "on_sale"})###");
    }

    mongocxx::cursor cursor = collection.find(allproduct.view());

    ParseProduct(products, descriptions, pictures, cursor);

    hide::maxpage = (products.size() / 9) - 1;
    if(products.size() % 9 != 0)
    {
        hide::maxpage++;
    }

    fullvector.push_back(products);
    fullvector.push_back(descriptions);
    fullvector.push_back(pictures);

    return fullvector;

}

std::string GetUser(std::string login)
{

    auto findername = bsoncxx::from_json(R"###({"salesman":")###" + login + R"###(", "type": "salesman"})###");
    auto cursor = collection.find_one(findername.view());

    if(cursor)
    {
        auto doc = cursor->view();
        std::string line = bsoncxx::to_json(doc);
        json document = json::parse(line);

        return Cleaner(document["password"]);
    }
    return "no password";
}

void handlerAddUserSite(const Request& req, Response& res)
{
    res.set_content(AddUser(), "text/html");
}

void handlerLogin(const Request& req, Response& res)
{
    //auto a = req.has_param("a") ? std::stoi( req.get_param_value("a") ) : 0;
    //auto b = req.has_param("b") ? std::stoi( req.get_param_value("b") ) : 0;

    PrintLog("login");
    // PublicProduct("asan");
    res.set_content(LogIn(), "text/html");
}

void handlerHadSite(const Request& req, Response& res)
{
    hide::status = hide::ChangeStatus::Hadsite;

    std::cout<< static_cast<int>(hide::status);
    hide::page = 0;
    int page = hide::page;
    PrintLog("send to had");

    res.set_content(siteHad(GetProducts(1), page), "text/html");
}

void handlerMyHadSite(const Request& req, Response& res)
{
    hide::status = hide::ChangeStatus::Myhadsite;

    std::cout<< static_cast<int>(hide::status);
    std::string login = hide::login;
    hide::page = 0;
    int page = hide::page;
    res.set_content(siteHad(GetProducts(3, 0, login), page), "text/html");
    PrintLog("send to myhad");
}

void PageUP(const Request& req, Response& res)
{
    std::string login = hide::login;
    int page = hide::page;
    std::cout<<"\nstatus"<<static_cast<int>(hide::status)<<'\n';
    PrintLog("maxpage" + std::to_string(hide::maxpage));
    if (hide::page + 1 <= hide::maxpage)
    {
        page = hide::page + 1;
        hide::page = page;

        if (hide::status == hide::ChangeStatus::Myhadsite)
        {
            res.set_content(siteHad(GetProducts(3, 0, login), page), "text/html");
        }
        if (hide::status == hide::ChangeStatus::Hadsite)
        {
            res.set_content(siteHad(GetProducts(1), page), "text/html");
        }
    }

    if (hide::status == hide::ChangeStatus::Myhadsite)
    {
        res.set_content(siteHad(GetProducts(3, 0, login), page), "text/html");
    }

    if (hide::status == hide::ChangeStatus::Hadsite)
    {
        res.set_content(siteHad(GetProducts(1), page), "text/html");
    }

}
void PageDown(const Request& req, Response& res)
{
    std::string login = hide::login;
    int page = hide::page;
    if (hide::page - 1 >= 0)
    {
        page = hide::page - 1;

        std::cout<<"\nstatus"<<static_cast<int>(hide::status)<<'\n';
        PrintLog("maxpage" + std::to_string(hide::maxpage));
        if (hide::status == hide::ChangeStatus::Myhadsite)
        {
            res.set_content(siteHad(GetProducts(3, 0, login), page), "text/html");
        }
        if (hide::status == hide::ChangeStatus::Hadsite)
        {
            res.set_content(siteHad(GetProducts(1), page), "text/html");
        }
    }
    if (hide::status == hide::ChangeStatus::Myhadsite)
    {
        res.set_content(siteHad(GetProducts(3, 0, login), page), "text/html");
    }

    if (hide::status == hide::ChangeStatus::Hadsite)
    {
        res.set_content(siteHad(GetProducts(1), page), "text/html");
    }
}

// no products vector
void handlerCheckLogin(const Request& req, Response& res) {
    std::string login = req.has_param("login") ? req.get_param_value("login") : "nologin";
    std::string password = req.has_param("password") ? req.get_param_value("password") : "nopasswd";

    PrintLog(login);
    PrintLog(password);
    hide::password = GetUser(login);
    hide::login = login;

    if(/*login != hide::login || */password != hide::password)
    {
        PrintLog("check failed 78");
        res.set_content(LogIn("failed"), "text/html");
    }else
    {
        PrintLog("on had of site");
        handlerHadSite(req, res);
    }
}

void ParserForOneProduct(std::vector<std::vector<std::string>>& comments, std::string productname, std::string productDeskription, std::string& picture, std::string& price)
{
    auto comentarray = bsoncxx::from_json(R"###({"productName":")###" + productname + R"###(",
                                            "productDeskription":")###" + productDeskription + R"###("})###");
    PrintLog("status: 1");

    auto cursor = collection.find_one(comentarray.view());

    PrintLog("status: 2");

    if(cursor)
    {
        PrintLog("status: 3");

        auto doc = *cursor;
        std::string doc_str = bsoncxx::to_json(doc);
        json doc_json = json::parse(doc_str);

        auto key_array = doc_json.at("comments").get<std::vector<std::vector<std::string>>>();
        picture = doc_json.at("picture").get<std::string>();
        price = doc_json.at("price").get<std::string>();

        for (const auto& array : key_array) {
            comments.push_back(array);
        }
        for (auto& arr : comments)
        {
            for(auto& str : arr)
            {
                PrintLog(str);
            }
        }
    }
    else
    {
        comments = {{"1", "2", "3"}, {"1", "2", "3"}, {"1", "2", "3"}};
        PrintLog("no document for product1");
    }
}

void handlerProduct(const Request& req, Response& res)
{
    std::string productname = req.has_param("productname") ? req.get_param_value("productname") : "0";
    std::string productDeskription = req.has_param("productDeskription") ? req.get_param_value("productDeskription") : "0";

    std::vector<std::vector<std::string>> comments;
    std::string picture;
    std::string price;

    PrintLog("geting on parserproduct");

    ParserForOneProduct(comments, productname, productDeskription, picture, price);
    hide::pictyre = picture;
    comments = DimensionsOfVector(comments);
    PrintLog("beginarr....");
    PrintArr(comments);
    PrintLog("endinarr....");

    hide::commentsArray = comments;
    hide::price = price;

    PrintLog("product page");
    PrintLog(productname);
    res.set_content(productPage(comments, productname, productDeskription, picture, price), "text/html");
}

// on base
void handlerAddtoBasket(const Request& req, Response& res)
{
    std::string productname = req.has_param("productname") ? req.get_param_value("productname") : "0";
    std::string productDeskription = req.has_param("productDeskription") ? req.get_param_value("productDeskription") : "0";

    auto basket = bsoncxx::from_json(R"###({"productName":")###" + productname + R"###(",
                                            "productDeskription":")###" + productDeskription + R"###("})###");

    auto cursor = collection.find_one(basket.view());

    if(cursor)
    {
        int page = hide::page;
        auto update_doc = bsoncxx::from_json(R"###({"$push": {"basket": ")###" + hide::login + R"###("}})###");
        collection.update_one(basket.view(), update_doc.view());

        res.set_content(siteHad(GetProducts(1), page), "text/html");
    }
    else
    {
         res.set_content("Product not found.", "text/plain");
    }


}

void handlerBasket(const Request& req, Response& res)
{
    int page = hide::page;
    std::string login = hide::login;
    res.set_content(siteHad(GetProducts(4, 0, login), page), "text/html");
}

void handlerAddComment(const Request& req, Response& res)
{
    auto newcomment = req.has_param("newcomment") ? req.get_param_value("newcomment") : "0";
    auto productdescription = req.has_param("productdescription") ? req.get_param_value("productdescription") : "0";
    auto productname = req.has_param("productname") ? req.get_param_value("productname") : "0";

    auto comment = bsoncxx::from_json(R"###({"productName":")###" + productname + R"###(",
                                            "productDeskription":")###" + productdescription + R"###("})###");

    auto cursor = collection.find_one(comment.view());

    if(cursor)
    {
        // добавить время
        auto update_doc = bsoncxx::from_json(R"###({"$push": {"comments": {"$each": [[")###" + newcomment + R"###(", ")###" + hide::login + R"###(", ")###" + ReturnTime() + R"###("]]}}})###");
        collection.update_one(comment.view(), update_doc.view());

        res.set_content(productPage(hide::commentsArray, productname, productdescription, hide::pictyre, hide::price), "text/html");
    }
    else
    {
        res.set_content("sonthing went wrong, plese try again:)", "text/plain");
    }
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// upload pictyre
json upload_file(const std::string& accessToken, const std::string& filePath, const std::string& fileContent) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://content.dropboxapi.com/2/files/upload";
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + accessToken).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
        headers = curl_slist_append(headers, ("Dropbox-API-Arg: {\"path\": \"/" + filePath + "\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}").c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fileContent.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, fileContent.size());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    std::cout << "Upload Response: " << readBuffer << std::endl;

    json response;
    try {
        response = json::parse(readBuffer);
    } catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        response["error"] = "JSON parse error";
    }

    return response;
}

json create_shared_link(const std::string& accessToken, const std::string& filePath) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://api.dropboxapi.com/2/sharing/create_shared_link_with_settings";
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + accessToken).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        json j;
        j["path"] = filePath;
        j["settings"]["requested_visibility"] = "public";

        std::string jsonString = j.dump();

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonString.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    std::cout << "Create Shared Link Response: " << readBuffer << std::endl;

    json response;
    try {
        response = json::parse(readBuffer);
    } catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        response["error"] = "JSON parse error";
    }

    return response;
}

void handle_upload(const Request& req, Response& res) {
    auto userphoto = req.has_param("userphoto") ? req.get_param_value("userphoto") : "no_param";
    auto file = req.get_file_value("file");


    // Сохраняем файл временно
    std::ofstream ofs(file.filename, std::ios::binary);
    ofs.write(file.content.data(), file.content.size());
    ofs.close();

    // ВАЖНО: Укажите здесь свой токен доступа Dropbox

    // Загружаем файл в Dropbox
    std::ifstream ifs(file.filename, std::ios::binary);
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string fileContent = buffer.str();

    std::string productname = hide::lastProductname;
    std::string productdescription = hide::lastProductdeskription;

    json uploadResponse = upload_file(accessToken, file.filename, fileContent);

    if (uploadResponse.contains("error")) {
        res.set_content("Upload Error: " + uploadResponse.dump(4), "application/json");
    } else {
        // Создаем ссылку на файл в Dropbox
        json linkResponse = create_shared_link(accessToken, "/" + file.filename);

        if (linkResponse.contains("error")) {
            res.set_content("Error: " + linkResponse.dump(4), "application/json");
        } else {
            // Проверяем и извлекаем URL из ответа
            std::string sharedLink;
            if (linkResponse.contains("url")) {
                sharedLink = linkResponse["url"];
            } else {
                sharedLink = "No URL found in response";
            }
            Rawer(sharedLink);
            hide::pictyre = sharedLink;

            std::string registerstatus = status::STATUS;
            PrintLog(userphoto);
            if(registerstatus == "product")
            {
                res.set_content(AddProductSite(), "text/html");
            }
            else
            {
                res.set_content(AddUser(), "text/html");
            }

        }
    }

    // Удаляем временный файл
    std::remove(file.filename.c_str());
}
// end uploading

void handlerOrder(const Request& req, Response& res)
{
    auto productname = req.has_param("productname") ? req.get_param_value("productname") : "noproduct";
    auto productDeskription = req.has_param("productDeskription") ? req.get_param_value("productDeskription") : "noproduct";
    auto productPicture = req.has_param("productPicture") ? req.get_param_value("productPicture") : "noproduct";

    PrintLog(productname);
    PrintLog(productDeskription);
    PrintLog(productPicture);

    auto order = bsoncxx::from_json(R"###({"productName":")###" + productname + R"###(",
                                            "productDeskription":")###" + productDeskription + R"###("})###");

    auto cursor = collection.find_one(order.view());

    if(cursor)
    {
        // добавить время
        auto update_doc = bsoncxx::from_json(R"###({"$set": {"status": "saled"}})###");
        collection.update_one(order.view(), update_doc.view());


    }
    res.set_content(productOrderedPage(productname, productDeskription, productPicture), "text/html");
    //res.set_content("product not found", "text/plain");

}

int main() {
    mongocxx::instance inst{};
    const auto uri = mongocxx::uri{ "mongodb+srv://mongo_user:LXkEj4dJLpY19PT0@cluster0.6yzdyrb.mongodb.net/" };

    mongocxx::client connection{ uri };
    collection = connection["new"]["one"];

    // auto result = collection.delete_many({});

    Server svr;
    std::cout<<'\n'<<" server is start... "<<'\n';
    svr.Get("/", handlerLogin);
    svr.Get("/checklogin", handlerCheckLogin);
    svr.Get("/product1", handlerProduct);
    svr.Get("/personalarea", handlerPersonalArea);
    svr.Get("/hadsite", handlerHadSite);
    svr.Get("/addproduct", handlerAddproductSite);
    svr.Get("/publicnewproduct", PublicProduct);
    svr.Get("/adduser", handlerAddUserSite);
    svr.Get("/publicnewuser", PublicUser);
    svr.Get("/pageup", PageUP);
    svr.Get("/pagedown", PageDown);
    svr.Get("/myhadsite", handlerMyHadSite);
    svr.Get("/basket", handlerBasket);
    svr.Get("/adbasket", handlerAddtoBasket);
    svr.Get("/addcomment", handlerAddComment);
    svr.Post("/upload", handle_upload);
    svr.Get("/order", handlerOrder);
    svr.listen("192.168.0.102", 8082);
}
