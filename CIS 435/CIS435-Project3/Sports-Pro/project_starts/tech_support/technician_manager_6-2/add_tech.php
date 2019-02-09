

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
    $sql = "INSERT INTO `technicians` ";
    $sql.= "( `techID`,`firstName`, `lastName`, `email`, `phone`,`password`)";
    $sql.= "VALUES ";
    $sql.= "(";
    $sql.= "'".$record['techID']."', ";
    $sql.= "'".$record['firstName']."', ";
    $sql.= "'".$record['lastName']."', ";
    $sql.= "'".$record['email']."', ";
    $sql.= "'".$record['phone']."', ";
    $sql.= "'".$record['password']."' ";
    $sql.=");";
    $result = $db->query($sql);
    if(!$result){
        throw new Exception('Cannot insert record');
    }
    $record['techID'] = $db->insert_id;
    return $record;
}

$record = [

    'techID' => $_POST["techID"],
    'firstName' => $_POST["firstName"],
    'lastName' => $_POST["lastName"],
    'email' => $_POST["email"],
    'phone' => $_POST["phone"],
    'password' => $_POST["password"]

];
$newRecord = insertRecord($db, $record);

include ('index.php');
?>



