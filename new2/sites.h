#define _CRT_SECURE_NO_WARNINGS
//#include <bsoncxx/json.hpp>
//#include <mongocxx/client.hpp>
//#include <mongocxx/instance.hpp>
#ifndef SITES_H
#define SITES_H
#include <iostream>
#include <string>
#include <vector>

namespace status
{
std::string STATUS;
}

std::string AddVector(std::vector<std::string>& products, std::vector<std::string>& description, std::vector<std::string>& pictyres)
{
    if(products.size() % 9 == 0)
    {
        return "normal vector";
    }else if(products.size() < 9)
    {
        for (int i = 0; products.size() < 9; i++)
        {
            products.push_back("no product");
        }
    }
    else{
        for (int i = 0; i < products.size() % 9; i++)
        {
            products.push_back("no product");
        }
    }
    if(description.size() % 9 == 0)
    {
        return "normal vector";
    }else if(description.size() < 9)
    {
        for (int i = 0; description.size() < 9; i++)
        {
            description.push_back("no description");
        }
    }
    else
    {
        for (int i = 0; i < description.size() % 9; i++)
        {
            description.push_back("no description");
        }
    }
    if(pictyres.size() % 9 == 0)
    {
        return "normal vector";
    }else if(pictyres.size() < 9)
    {
        for (int i = 0; pictyres.size() < 9; i++)
        {
            pictyres.push_back("no pictyre");
        }
    }
    else{
        for (int i = 0; i < pictyres.size() % 9; i++)
        {
            pictyres.push_back("no pictyre");
        }
    }
    return "done\n";
}

// logic functions

std::string LogIn(std::string status = "login")
{
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"] {
            margin-bottom: 10px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            text-align: center;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>войдите в свой личный кабинет</h1>
        <form action="/checklogin" method="get">
            <input type="text" name="login" placeholder="Введите логин" required>
            <input type="text" name="password" placeholder="Введите пароль" required>
            <button type="submit">войти</button>
        </form>
        <a href="adduser"><button>зарегистрироваться</button></a>
    </div>
</body>
</html>

)###";

}

std::string siteHad(std::vector<std::vector<std::string>> fullvector, int page)
{
    std::vector<std::string> products = fullvector[0];
    std::vector<std::string> description = fullvector[1];
    std::vector<std::string> pictyres = fullvector[2];

    std::cout<<AddVector(products, description, pictyres);

    std::string link = "https://www.dropbox.com/scl/fi/54pw73yf1efjq8pznhd7p/swappy-20240613_140543.png?rlkey=riml3r9seeljrk7umm6rwdjib&dl=0";

    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Client for online shop</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        button.btn-primary {
            background-color: transparent; /* Прозрачный фон */
            color: #009900; /* Цвет текста */
            padding: 0; /* Убираем внутренние отступы */
            border: none; /* Убираем границу */
            font-size: 16px; /* Размер текста */
            cursor: pointer;
        }
        button.btn-primary:hover {
            text-decoration: underline; /* Подчеркнутый текст при наведении */

        }
        button.btn-secondary {
            background-color: #28a745; /* Основной цвет кнопки */
            color: white; /* Цвет текста */
            padding: 1px 5px; /* Размер кнопки */
            border: none;
            border-radius: 5px;
            font-size: 12px; /* Размер текста */
            cursor: pointer;
        }
        button.btn-secondary:hover {
            background-color: #218838; /* Цвет при наведении */
        }
        nav {
            display: flex;
            justify-content: center;
            background-color: #444;
        }
        nav a {
            color: #fff;
            padding: 14px 20px;
            text-decoration: none;
            text-align: center;
        }
        nav a:hover {
            background-color: #555;
        }
        .container {
            padding: 20px;
            display: flex;
            flex-wrap: wrap;
            justify-content: space-around;
        }
        .product {
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
            padding: 15px;
            margin: 10px;
            text-align: center;
            flex-basis: calc(33.333% - 20px);
            box-sizing: border-box;
        }
        .product img {
            max-width: 100%;
            height: auto;
        }
        .product h2 {
            font-size: 1.5em;
            margin: 10px 0;
        }
        .product p {
            font-size: 1em;
            color: #555;
        }

        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;

            width: 100%;
            bottom: 0;
        }
        .pagination {
          display: inline-block;
          margin-bottom: 1cm;
          text-align: center;
        }

        .pagination a {
          color: black;
          padding: 8px 16px;
          text-decoration: none;
          transition: background-color .3s;
          display: inline-block;
        }

        .pagination a.active {
          background-color: #4CAF50;
          color: white;
        }

        .pagination a:hover:not(.active) {background-color: #ddd;}
    </style>
</head>
<body>
    <header>
        <h3>Добро пожаловать в наш интернет-магазин</h3>
        <p><font size="6" color="white" face="fantasy">STREET STYLE</font></p>
    </header>
    <nav>
        <a href="/personalarea">личный кабинет</a>
        <a href="/hadsite">Главная</a>
        <a href="#">Магазин</a>
        <a href="#">О нас</a>
        <a href="/basket">корзина</a>
        <a href="/">выйти</a>
    </nav>
    <div class="container">
        <div class="product">
            <img src=")###" + pictyres[0 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[0 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[0 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[0 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[0 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[0 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[0 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[1 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[1 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[1 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[1 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[1 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[1 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[1 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[2 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[2 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[2 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[2 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[2 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[2 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[2 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[3 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[3 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[3 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[3 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[3 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[3 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[3 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[4 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[4 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[4 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[4 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[4 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[4 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[4 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[5 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[5 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[5 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[5 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[5 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[5 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[5 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
        <div class="product">
            <img src=")###" + pictyres[6 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[6 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[6 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[6 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[6 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[6 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[6 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>


        <div class="product">
            <img src=")###" + pictyres[7 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[7 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[7 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[7 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[7 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[7 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[7 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>


        <div class="product">
            <img src=")###" + pictyres[8 + (9 * page)] + R"###(" alt="нет картинки">
            <form action="/product1" method="get">
                <input type="hidden" name="productname" value=")###" + products[8 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[8 + (9 * page)] + R"###(">
                <button type="submit" class="btn-primary"><h2>)###" + products[8 + (9 * page)] + R"###(</h2></button>
            </form>
            <p>)###" + description[8 + (9 * page)] + R"###(</p>

            <form action="/adbasket" method="get">
                <input type="hidden" name="productname" value=")###" + products[8 + (9 * page)] + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description[8 + (9 * page)] + R"###(">

                <button type="submit" class="btn-secondary"><h3>добавить в корзину</h3></button>
            </form>
        </div>
    </div>
    <div class="pagination">
      <a href="/pagedown">&laquo;</a>
      <a href="#" class="active">)###" + std::to_string(page) + R"###(</a>
      <a href="/pageup">&raquo;</a>
    </div>
    <footer>
        &copy; 2024 Интернет-магазин. Все права защищены.
    </footer>
</body>
</html>
)###";


}

std::string productPage(std::vector<std::vector<std::string>> comments,
                        std::string productname,
                        std::string description,
                        std::string picture,
                        std::string price)
{

    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Страница продукта</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        form {
              background-color: #f9f9f9;
              border: 1px solid #ccc;
              border-radius: 5px;
              padding: 20px;
              max-width: 820px;
              margin: 20px auto;
              box-shadow: 0 2px 4px rgba(0,0,0,0.1);
          }

          form h3 {
              margin-top: 0;
              margin-bottom: 15px;
              font-size: 18px;
          }

          form input[type="text"] {
              width: 90%;
              padding: 10px;
              margin-bottom: 10px;
              border: 1px solid #ccc;
              border-radius: 4px;
          }

          form button {
              background-color: #4CAF50;
              color: white;
              padding: 10px 15px;
              border: none;
              border-radius: 4px;
              cursor: pointer;
              font-size: 16px;
          }

          form button:hover {
              background-color: #45a049;
          }
        nav {
            display: flex;
            justify-content: center;
            background-color: #444;
        }
        nav a {
            color: #fff;
            padding: 14px 20px;
            text-decoration: none;
            text-align: center;
        }
        nav a:hover {
            background-color: #555;
        }
        .container {
            padding: 20px;
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
        }
        .product-img {
            text-align: center;
        }
        .product-img img {
            max-width: 100%;
            height: auto;
            border-radius: 5px;
        }
        .product-info {
            margin-top: 20px;
        }
        .product-title {
            font-size: 2em;
            margin-bottom: 10px;
        }
        .product-description {
            font-size: 1.2em;
            color: #555;
        }
        .reviews {
            margin-top: 30px;
        }
        .review {
            border-top: 1px solid #ddd;
            padding-top: 10px;
            margin-top: 10px;
        }
        .review h3 {
            margin: 0;
            font-size: 1.5em;
        }
        .review p {
            margin: 5px 0;
            color: #777;
        }
        .review span {
            display: block;
            font-size: 0.9em;
            color: #999;
        }
        .product-price {
            display: inline-block;
            color: blue;
            font-size: 24px;
            margin-left: 10px;
        }
        .btn-primary {
            display: inline-block;
            vertical-align: middle;
        }
        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;
        }
    </style>
</head>
<body>
    <header>
        <h1>Интернет-магазин</h1>
    </header>
    <nav>
        <a href="/hadsite">Главная</a>
        <a href="#">Магазин</a>
        <a href="#">О нас</a>
        <a href="#">Контакты</a>
    </nav>
    <div class="container">
        <div class="product-img">
            <img src=")###" + picture + R"###(" alt="Изображение продукта">
        </div>
        <div class="product-info">

            <form action="/order" method="get">
                <input type="hidden" name="productname" value=")###" + productname + R"###(">
                <input type="hidden" name="productDeskription" value=")###" + description + R"###(">
                <input type="hidden" name="productPicture" value=")###" + picture + R"###(">

                <button type="submit" class="btn-primary"><h2>заказать</h2></button>
                <span class="product-price">Цена: )###" + price + R"###( руб.</span>
            </form>

            <h2 class="product-title">)###" + productname + R"###(</h2>
            <p class="product-description">)###" + description + R"###(</p>
        </div>
        <div class="reviews">
            <h2>Отзывы</h2>
            <div class="review">
                <h3>Новейший отзыв</h3>
                <p>)###" + comments[2][0] + R"###(</p>
                <span>Автор: )###" + comments[2][1] + R"###(</span>
                <span>Дата: )###" + comments[2][2] + R"###(</span>
            </div>
            <div class="review">
                <h3>Актуальный отзыв</h3>
                <p>)###" + comments[1][0] + R"###(</p>
                <span>Автор: )###" + comments[1][1] + R"###(</span>
                <span>Дата: )###" + comments[1][2] + R"###(</span>
            </div>
            <div class="review">
                <h3>Устаревший отзыв</h3>
                <p>)###" + comments[0][0] + R"###(</p>
                <span>Автор: )###" + comments[0][1] + R"###(</span>
                <span>Дата: )###" + comments[0][2] + R"###(</span>
            </div>
            <form action="/addcomment" method="get">
                <h3>введите комментарий</h3>
                <input type="text" id="coment" name="newcomment" placeholder="введите комментарий..." required>
                <input type="hidden" name="productname" value=")###" + productname + R"###(">
                <input type="hidden" name="productdescription" value=")###" + description + R"###(">
                <button type="submit">опубликовать</button>

            </form>
        </div>
    </div>
    <footer>
        &copy; 2024 Интернет-магазин. Все права защищены.
    </footer>
</body>
</html>

)###";
}

std::string productOrderedPage(std::string productname,
                                std::string description,
                                std::string picture)
{

    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Страница продукта</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        form {
              background-color: #f9f9f9;
              border: 1px solid #ccc;
              border-radius: 5px;
              padding: 20px;
              max-width: 820px;
              margin: 20px auto;
              box-shadow: 0 2px 4px rgba(0,0,0,0.1);
          }

          form h3 {
              margin-top: 0;
              margin-bottom: 15px;
              font-size: 18px;
          }

          form input[type="text"] {
              width: 90%;
              padding: 10px;
              margin-bottom: 10px;
              border: 1px solid #ccc;
              border-radius: 4px;
          }

          form button {
              background-color: #4CAF50;
              color: white;
              padding: 10px 15px;
              border: none;
              border-radius: 4px;
              cursor: pointer;
              font-size: 16px;
          }

          form button:hover {
              background-color: #45a049;
          }
        nav {
            display: flex;
            justify-content: center;
            background-color: #444;
        }
        nav a {
            color: #fff;
            padding: 14px 20px;
            text-decoration: none;
            text-align: center;
        }
        nav a:hover {
            background-color: #555;
        }
        .container {
            padding: 20px;
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
        }
        .product-img {
            text-align: center;
        }
        .product-img img {
            max-width: 100%;
            height: auto;
            border-radius: 5px;
        }
        .product-info {
            margin-top: 20px;
        }
        .product-title {
            font-size: 2em;
            margin-bottom: 10px;
        }
        .product-description {
            font-size: 1.2em;
            color: #555;
        }
        .reviews {
            margin-top: 30px;
        }
        .review {
            border-top: 1px solid #ddd;
            padding-top: 10px;
            margin-top: 10px;
        }
        .review h3 {
            margin: 0;
            font-size: 1.5em;
        }
        .review p {
            margin: 5px 0;
            color: #777;
        }
        .review span {
            display: block;
            font-size: 0.9em;
            color: #999;
        }
        footer {
            background-color: #333;
            color: #fff;
            text-align: center;
            padding: 10px 0;
        }
    </style>
</head>
<body>
    <header>
        <h1>Интернет-магазин</h1>
    </header>
    <nav>
        <a href="/hadsite">Главная</a>
        <a href="#">Магазин</a>
        <a href="#">О нас</a>
        <a href="#">Контакты</a>
    </nav>
    <div class="container">
        <div class="product-img">
            <img src=")###" + picture + R"###(" alt="Изображение продукта">
        </div>
        <div class="product-info">
            <p href="/order" >товар куплен ожидайте заказа в ближайшее время</p>
            <h2 class="product-title">)###" + productname + R"###(</h2>
            <p class="product-description">)###" + description + R"###(</p>
        </div>
    </div>
    <footer>
        &copy; 2024 Интернет-магазин. Все права защищены.
    </footer>
</body>
</html>

)###";
}

std::string PersonalArea(std::string name, std::string description, std::string picture, std::vector<std::vector<std::string>> comments)
{
    return R"###(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        img {
            max-width: 100%;
            height: auto;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
        }
        button:hover {
            background-color: #0056b3;
        }
        .reviews {
            margin-top: 30px;
        }
        .review {
            border-top: 1px solid #ddd;
            padding-top: 10px;
            margin-top: 10px;
        }
        .review h3 {
            margin: 0;
            font-size: 1.5em;
        }
        .review p {
            margin: 5px 0;
            color: #777;
        }
        .review span {
            display: block;
            font-size: 0.9em;
            color: #999;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Личный кабинет</h1>
        <img src=")###" + picture + R"###(" alt="Ваша картинка">
        <p><strong>Имя:</strong>)###" + name + R"###(</p>
        <p><strong>Описание:</strong>)###" + description + R"###(</p>

        <h2>Отзывы</h2>
            <div class="review">
                <h3>Новейший отзыв</h3>
                <p>)###" + comments[2][0] + R"###(</p>
                <span>Автор: )###" + comments[2][1] + R"###(</span>
                <span>Дата: )###" + comments[2][2] + R"###(</span>
            </div>
            <div class="review">
                <h3>Актуальный отзыв</h3>
                <p>)###" + comments[1][0] + R"###(</p>
                <span>Автор: )###" + comments[1][1] + R"###(</span>
                <span>Дата: )###" + comments[1][2] + R"###(</span>
            </div>
            <div class="review">
                <h3>Устаревший отзыв</h3>
                <p>)###" + comments[0][0] + R"###(</p>
                <span>Автор: )###" + comments[0][1] + R"###(</span>
                <span>Дата: )###" + comments[0][2] + R"###(</span>
            </div>
            <a href="/myhadsite"><button>Мои продукты</button></a>
        <a href="/addproduct"><button>добавить продукт</button></a>
        <a href="/basket"><button>корзина</button></a>
    </div>


</body>
</html>

)###";
}

std::string AddProductSite()
{
    status::STATUS = "product";
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
            color: #333;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"], input[type="file"] {
            margin-bottom: 15px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            transition: background-color 0.3s;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
            transition: background-color 0.3s;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            justify-content: space-between;
        }
        .button-container a {
            flex: 1;
            margin: 5px;
            text-align: center;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Заполните форму для добавления товара</h1>
        <h2>2 простых шага</h2>
        <h2>шаг 1: загрузите файл, после перезагрузки продолжите заполнять форму</h2>

        <form action="/upload" method="post" enctype="multipart/form-data">
            <input type="file" name="file" id="file">
            <button type="submit">Загрузить</button>
        </form>
        <h2>шаг 2: введите свои данные</h2>
        <form action="/publicnewproduct" method="get">
            <input type="text" name="productname" placeholder="Введите название" required>
            <input type="text" name="productdescription" placeholder="Введите описание" required>
            <input type="text" name="price" placeholder="Введите цену" required>
            <button type="submit">Добавить</button>
        </form>



        <div class="button-container">
            <a href="/personalarea" class="button">назад</a>
            <a href="/hadsite" class="button">на главную</a>
        </div>
    </div>
</body>
</html>


)###";
}

std::string AddUser()
{
    status::STATUS = "user";
    return R"###(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Личный кабинет</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            font-size: 1.5em;
            margin-bottom: 20px;
        }
        form {
            display: flex;
            flex-direction: column;
        }
        input[type="text"] {
            margin-bottom: 10px;
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 100%;
            box-sizing: border-box;
        }
        button {
            background-color: #007bff;
            color: #fff;
            border: none;
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1em;
            border-radius: 5px;
            margin-bottom: 10px;
            text-align: center;
        }
        button:hover {
            background-color: #0056b3;
        }
        a.button {
            display: inline-block;
            text-decoration: none;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            font-size: 1em;
            text-align: center;
            margin-top: 10px;
        }
        a.button:hover {
            background-color: #0056b3;
        }
        .button-container {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>регистрация</h1>
        <form action="/upload" method="post" enctype="multipart/form-data">

            <input type="file" name="file" id="file">
            <input type="hidden" name="userphoto" value="yes">
            <button type="submit">Загрузить</button>
        </form>
        <form action="/publicnewuser" method="get">
            <input type="text" id="inputField" name="login" placeholder="придумайте логин" required>
            <input type="text" id="inputField" name="password" placeholder="придумайте пароль" required>
            <input type="text" id="inputField" name="description" placeholder="опишите себя">
            <button type="submit">зарегистрироваться</button>
        </form>
        <div class="button-container">
            <a href="/hadsite" class="button">на главную</a>
        </div>
    </div>
</body>
</html>

)###";
}

#endif // SITES_H
