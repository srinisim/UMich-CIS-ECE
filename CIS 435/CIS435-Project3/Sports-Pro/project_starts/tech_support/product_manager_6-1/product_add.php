<?php include "../view/header.php" ?>


    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" media="screen" href="../main.css"/>
    </head>
    <body>
    <main>
    <h1>Add Product</h1>
    <form id="aligned" action="itemAdder.php" method="post">
        <label for="name">Name: </label>
        <input type="text" name="name"><br>

        <label for="productCode">Product Code: </label>
        <input type="text" name="productCode"><br>

        <label for="countryCodeUpdated">Version: </label>
        <input type="text" name="version"><br>

        <label for="releaseDate">Release Date: </label>
        <input type="text" name="releaseDate">Use 'yyyy-mm-dd' format<br>

        <label for="Add Product"></label>
        <input type="submit" name="Add Product" value="Add Product">
    </form>
    <p><a href="index.php">View Products</a></p>
    </main>
    </body>

    </html>



<?php include "../view/footer.php"?>