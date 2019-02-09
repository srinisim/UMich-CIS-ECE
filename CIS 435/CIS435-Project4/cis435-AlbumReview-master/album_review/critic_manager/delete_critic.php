<?php

$host    = "localhost";
$user    = "ts_user";
$pass    = "pa55word";
$db_name = "album_review";

$db =new mysqli($host, $user, $pass, $db_name);
if($db->connect_error)
{
    die("Cannot connect to database: \n"
        . $db->connect_error . "\n"
        . $db->connect_errno
    );

}


function fetchAlll(mysqli $db)
{
    $data = [];

    $sql = 'SELECT * FROM critics ';

    $results = $db->query($sql);

    if ($results->num_rows > 0) {
        while ($row = $results->fetch_object()) {
            $data[] = $row;
        }
    }
    return $data;
}
$records = fetchAlll($db);


function deleteRecord(mysqli $db, $criticID){
    $sql = "DELETE FROM critics WHERE criticID = '".$criticID."'";
    $result = $db->query($sql);
    if(!$result){
        throw new Exception('Cannot delete record');
    }
}

$productCode = filter_input(INPUT_GET,'criticID',FILTER_DEFAULT);

if(empty($productCode)){
    die('ID is invalid');
}

deleteRecord($db,$productCode);

include ('index.php')

?>
