<?php
echo "<table border='2' style='border-collapse:collapse;''>";
	for ($i=1; $i < 10; $i++) { 
		echo "<tr margin='0'>";
		for ($j=1; $j <10; $j++) {
			if($i<$j){
				echo "<td>";
				echo " ";
				//echo "&nbsp";
				echo "</td>";
			}
			else{
				echo "<td >";
				echo "{$i}X{$j}=".$i*$j." ";
				echo "</td>";
			}
		}		
		echo "</tr>";
	}
	echo "</table>";
?>
