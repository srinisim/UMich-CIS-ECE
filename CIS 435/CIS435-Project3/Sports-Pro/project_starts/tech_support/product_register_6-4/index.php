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
		<h3>Customer Login</h3>

		<p>You must login before you can register a product</p>

		<form action="product_registration.php" method="post">
			<label for="loginEmail">Email: </label>
			<input type="text" name="loginEmail">
			<input type="submit" value="Login">
		</form>
	</main>
</body>
</html>
<?php include '../view/footer.php'; ?>