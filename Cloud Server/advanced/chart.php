<div id="areachart"></div>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">
// Load google charts
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart);
// Draw the chart and set the chart values
function drawChart() {
  var data = google.visualization.arrayToDataTable([
  ['Time Stamp', 'Celsius']
<?php
//check if request is empty
if(empty($_GET["l"]))
die();
$file = fopen("data","r");
while(! feof($file))
  {
  $row=fgetcsv($file);
  		if($row[0]==$_GET["l"])
  			echo ",['{$row["1"]}',{$row["2"]}]";
  }
fclose($file);
?>  
]);
  // Optional; add a title and set the width and height of the chart
  var options = {'title':'Temperature Analytics @ <?php echo $_GET["l"]; ?>', 'width':550, 'height':400};
  // Display the chart inside the <div> element with id="areachart"
  var chart = new google.visualization.AreaChart(document.getElementById('areachart'));
  chart.draw(data, options);
}
</script>