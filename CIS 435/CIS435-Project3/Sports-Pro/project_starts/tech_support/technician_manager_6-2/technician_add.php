<?php include "../view/header.php" ?>


    <!DOCTYPE>
    <html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" media="screen" href="../main.css"/>
    </head>
    <body>
    <main>
    <h1>Technician List</h1>
    <form id="aligned" action="add_tech.php" method="post">
        <!-- <label for="name">Name: </label>
        Tech ID: <input type="text" name="techID"><br> -->

        <label for="firstName">First Name: </label>
        <input type="text" name="firstName"><br>

        <label for="lastName">Last name: </label>
        <input type="text" name="lastName"><br>

        <label for="email">Email: </label>
        <input type="text" name="email"><br>

        <label for="phone">Phone: </label>
        <input type="text" name="phone"><br>

        <label for="password">Password: </label>
        <input type="text" name="password"><br>

        <label for="Add technician"></label>
        <input type="submit" name="Add technician" value="Add technician">
    </form>
    <p><a href="index.php">View Technicians List</a></p>
    </main>
    </body>

    </html>



<?php include "../view/footer.php"?>