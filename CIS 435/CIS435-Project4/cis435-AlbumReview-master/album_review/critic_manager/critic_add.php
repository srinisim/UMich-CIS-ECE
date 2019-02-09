<?php include "../view/header.php" ?>


    <!DOCTYPE>
    <html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" media="screen" href="../main.css"/>
    </head>
    <body>
    <main>
    <h1>Critic List</h1>
    <form id="aligned" action="add_critic.php" method="post">
        <!-- <label for="name">Name: </label>
        Critic ID: <input type="text" name="criticID"><br> -->

        <label for="firstName">First Name: </label>
        <input type="text" name="firstName"><br>

        <label for="lastName">Last name: </label>
        <input type="text" name="lastName"><br>

        <label for="email">Email: </label>
        <input type="text" name="email"><br>

        <label for="password">Password: </label>
        <input type="text" name="password"><br>

        <label for="Add Critic"></label>
        <input type="submit" name="Add Critic" value="Add critic">
    </form>
    <p><a href="index.php">View Critics List</a></p>
    </main>
    </body>

    </html>



<?php include "../view/footer.php"?>
