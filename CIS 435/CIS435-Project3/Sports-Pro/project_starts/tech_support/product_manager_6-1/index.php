<?php include "../view/header.php" ?>


<?php
$host    = "localhost";
$user    = "ts_user";
$pass    = "pa55word";
$db_name = "tech_support";

$db =new mysqli($host, $user, $pass, $db_name);
if($db->connect_error)
{
    die("Cannot connect to database: \n"
        . $db->connect_error . "\n"
        . $db->connect_errno
    );

}




function fetchAll(mysqli $db)
{
    $data = [];

    $sql = 'SELECT * FROM products ';

    $results = $db->query($sql);

    if ($results->num_rows > 0) {
        while ($row = $results->fetch_object()) {
            $data[] = $row;
        }
    }
    return $data;
}

$records = fetchAll($db);

?>

    <!DOCTYPE>
    <html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" media="screen" href="../main.css"/>
    </head>

    <body>
    <main>
    <h1>Product List</h1>
    <table>
        <tr>
            <th>Code</th>
            <th>Name</th>
            <th>Version</th>
            <th>Release Date</th>
            <th></th>
        </tr>
        <?php foreach($records as $record): ?>
            <tr>
                <td><?php echo $record->productCode; ?></td>
                <td><?php echo $record->name; ?></td>
                <td><?php echo $record->version; ?></td>
                <td><?php echo $record->releaseDate; ?></td>
                <td>
                <form>
                    <a href="delete_product.php?productCode=<?php echo $record->productCode;?>">Delete</a>
                </form>
                </td>
            </tr>
        <?php endforeach;
        ?>
    </table>
    <p><a href="product_add.php">Add product</a></p>
    </main>
    </body>

    </html>



<?php include "../view/footer.php"?>