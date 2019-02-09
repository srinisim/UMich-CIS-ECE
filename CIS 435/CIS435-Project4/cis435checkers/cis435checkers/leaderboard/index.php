<?php include '../view/header.php'; ?>
<?php 
	try {
		require __DIR__ . "/../model/database.php";
        require __DIR__ . "/../model/players_db.php";
        
		$playerList = select_players();
		$rank = 1;
    }
    catch (Exception $e) {
        echo 'Caught exception: ',  $e->getMessage(), "\n";
    }
?>
<main>
    <h3>Leaderboard</h3>
		<table>
			<tr>
				<th>Rank</th>
				<th>Player ID</th>
				<th>Name</th>
                <th>Wins</th>
                <th>Losses</th>
			</tr>
			<?php foreach ($playerList as $player): ?>
			<tr>
                <td><?php echo $rank; $rank++; ?></td>
				<td><?php echo $player['playerID']; ?></td>
                <td><?php echo $player['firstName'] . " " . $player['lastName']; ?></td>
				<td><?php echo $player['wins']; ?></td>
				<td><?php echo $player['losses']; ?></td>
			</tr>
			<?php endforeach; ?>
		</table>  
</main>
<?php include '../view/footer.php'; ?>