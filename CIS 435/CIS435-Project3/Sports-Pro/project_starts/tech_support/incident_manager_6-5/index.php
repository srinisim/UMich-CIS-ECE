<?php include '../view/header.php'; ?>
<!DOCTYPE <!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<!-- <title>Page Title</title> -->
		<link rel="stylesheet" type="text/css" media="screen" href="../main.css" />
	</head>
	<body>
		<main>
			<h3>Get Customer</h3>
			<p>You must enter the customer's email address to select the customer.</p><br>
			<form action="incident_creation.php" method="post">
				<label for="emailSearched">Email: </label>
				<input type="text" name="emailSearched">
				<input type="submit" value="Get Customer">
			</form>
		</main>
	</body>
</html>
<?php include '../view/footer.php'; ?>