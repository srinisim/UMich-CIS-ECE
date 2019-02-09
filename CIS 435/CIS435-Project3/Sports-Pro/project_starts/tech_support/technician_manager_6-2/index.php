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

    $sql = 'SELECT * FROM technicians';

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
    <h1>Technician List</h1>
    <table>

            <th>First Name</th>
            <th>Last Name</th>
            <th>Email</th>
            <th>Phone</th>
            <th>Password</th>
        <th></th>

        </tr>
        <?php



        foreach($records as $record): ?>
            <tr>
                <td><?php echo $record->firstName; ?></td>
                <td><?php echo $record->lastName; ?></td>
                <td><?php echo $record->email; ?></td>
                <td><?php echo $record->phone; ?></td>
                <td><?php echo $record->password; ?></td>

                <td>
                    <a href="delete_tech.php?techID=<?php echo $record->techID;?>">Delete</a>
                </td>
            </tr>
        <?php endforeach;
        ?>
    </table>
    <p><a href="technician_add.php">Add technician</a></p>
    </main>
    </body>

    </html>



<?php include "../view/footer.php"?>