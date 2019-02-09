

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



function  insertRecord(mysqli $db, array $record){
    $sql = "INSERT INTO `products` ";
    $sql.= "(`productCode`, `name`, `version`, `releaseDate`)";
    $sql.= "VALUES ";
    $sql.= "(";
    $sql.= "'".$record['productCode']."', ";
    $sql.= "'".$record['name']."', ";
    $sql.= "'".$record['version']."', ";
    $sql.= "'".$record['releaseDate']."' ";
    $sql.=");";
    $result = $db->query($sql);
    if(!$result){
        throw new Exception('Cannot insert record');
    }
    $record['productCode'] = $db->insert_id;
    return $record;
}

$record = [
    'productCode' => $_POST["productCode"],
    'name' => $_POST["name"],
    'version' => $_POST["version"],
    'releaseDate' => $_POST["releaseDate"],
];
$newRecord = insertRecord($db, $record);

include ('index.php');
?>



