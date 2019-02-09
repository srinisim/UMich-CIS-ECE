<?php include '../view/header.php'; ?>
<?php 
    try {
        require __DIR__ . "/../model/database.php";
        require __DIR__ . "/../model/album_db.php";

        $albumList = select_all_albums();
    }
    catch(Exception $e) {
        echo 'Caught exception: ',  $e->getMessage(), "\n";
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<link rel="stylesheet" type="text/css" href="../main.css">
	<title>Album Review Charts</title>
</head>
<body>
<main>
    <h3>Album Charts</h3>
	<table>
		<tr>
			<th>Title</th>
			<th>Artist</th>
			<th>Rating</th>
            <th>Release Date</th>
		</tr>
		<?php foreach ($albumList as $album): ?>
		<tr>
			<td><?php echo $album['title']; ?></td>
			<td><?php echo $album['artist']; ?></td>
			<td><?php echo $album['rating']; ?></td>
			<td><?php echo $album['releaseDate']; ?></td>
		</tr>
		<?php endforeach; ?>
	</table>
</main>
</body>
</html>
<?php include '../view/footer.php'; ?>