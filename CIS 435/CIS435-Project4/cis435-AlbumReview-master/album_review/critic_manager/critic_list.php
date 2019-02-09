<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <!-- <title>Page Title</title> -->
    <link rel="stylesheet" type="text/css" href="../main.css" />
</head>
<body>
    <main>
	  	<h3>Results</h3>
			<table>
				<tr>
					<th>Name</th>
					<th>Email Address</th>
					<th>Password</th>
					<th></th>
				</tr>
				<?php foreach ($criticList as $critic): ?>
				<tr>
					<td><?php echo $critic['firstName'] . " " . $critic['lastName']; ?></td>
					<td><?php echo $critic['email']; ?></td>
					<td><?php echo $critic['password']; ?></td>
					<td>
						<form action="critic_view_update.php" method="post">
							<input type="hidden" name="criticID" value="<?php echo $critic['criticID'] ?>">
							<input type="submit" value="Select">
						</form>
					</td>
				</tr>
			    <?php endforeach; ?>
		</table>
    </main>
</body>
</html>
