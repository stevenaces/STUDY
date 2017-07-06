<?php
	$ArrFruits = array("orange","apple","banana" );
	$ArrLanguages = array("en"=>"English","cn"=>"Chinese");
	echo "输出ArrLanguages数组元素：";
	var_dump($ArrLanguages);
	echo "<br/>";
	echo "输出ArrFruits数组元素：";
	var_dump($ArrFruits);
	echo "<br/>";
	echo "使用print_r输出ArrFruits数组元素：";
	print_r($ArrFruits);
	unset($ArrFruits[1]);
	echo "<br/>";
	echo "使用unset()方法删除ArrFruits[1]输出ArrFruits数组元素：";
	print_r($ArrFruits);
	echo "<br/>";

	/*常用数组函数*/
	$today = getdate();
	print_r($today);
	echo "<br/>";

	echo "使用count()获得ArrLanguages数组大小：".
	count($ArrLanguages);
	echo "<br/>";

	echo "使用in_array()检查数组中是否包含某个值：";
	$i = in_array('banana', $ArrFruits);
	printf("%d",$i);
	echo "<br/>使用var_dump打印in_array返回值：";
	var_dump(in_array('banana', $ArrFruits));
	echo "<br/>";

	$ArrNumber = range(1,20);
	print_r($ArrNumber);
	echo "<br/>";
	$ArrLetter = range('a','i');
	print_r($ArrLetter);
	echo "<br/>";

	/*遍历数组*/
	/*for循环遍历*/
	echo '使用for遍历$Arrletter数组：';
	$count = count($ArrLetter);
	for ($i=0; $i <$count ; $i++) { 
		echo $ArrLetter[$i];
	}
	echo "<br/>";

	/*使用数组指针遍历*/
	$ArrFruits2 = array("apple","orange","banana");
	echo "使用数组指针遍历:"."<br/>";
	echo current($ArrFruits2);echo "<br/>";
	each($ArrFruits2);
	echo current($ArrFruits2);echo "<br/>";
	next($ArrFruits2);
	echo current($ArrFruits2);echo "<br/>";
	end($ArrFruits2);

	print_r(each($ArrFruits2));
	echo "<br/>";

	/*使用list()函数把数组中的值赋给变量*/
	echo "使用list()函数把数组中的值赋给变量:"."<br/>";
	list($fruit1,$fruit2,$fruit3) = $ArrFruits2;
	echo $fruit1." ".$fruit2." ".$fruit3."<br/>";

	/*使用其他循环语句*/
	echo "使用do-while语句遍历数组:";
	$ArrFruits4 = array("apple","orange","banana");
	do{
		echo key($ArrFruits4)." ".current($ArrFruits4);
	}while(next($ArrFruits4));
	echo "<br/>";
	
	reset($ArrFruits4);		//将数组指针指向第一个元素
	echo "使用while语句遍历数组:";
	while ($arr = each($ArrFruits4)) {
		echo $arr['key'].' '.$arr['value'];
	}
	echo "<br/>";

	reset($ArrFruits4);		//将数组指针指向第一个元素
	echo "使用while语句遍历数组:";
	while(list($key,$value) = each($ArrFruits4)){
		echo $key." ".$value;
	}
	echo "<br/>";

	/*foreach循环遍历*/
	$ArrProduct = array(
		'pname'=>'NOKIA N97',
		'price'=>'1500',
		'pubtime'=>'2008',
		);		//注意“，”和“；”
	echo "使用foreach遍历数组:".'<br/>';
	if (is_array($ArrProduct)&&!empty($ArrProduct)) {
		foreach ($ArrProduct as $key => $value) {
			echo $key.":".$value."<br/>";
		}
	}
	echo "<br/>";

	/*排序*/
	echo "ArrNumber排序前："."<br/>";
	print_r($ArrNumber);echo "<br/>";	//ArrNumber数组在第34行定义
	echo "使用rsort(),sort()排序后："."<br/>";
	rsort($ArrNumber);	//降序
	print_r($ArrNumber);echo "<br/>";
	sort($ArrNumber);	//升序
	print_r($ArrNumber);echo "<br/>";

	$ArrFruits5 = array("l"=>"lemon","o"=>"orange","b"=>"banana","a"=>"apple");
	ksort($ArrFruits5);
	print_r($ArrFruits5);echo "<br/>";

	$result = array(
			array(
				'pname' => "NOKIA N73",
				'price' => "1500",
				),
			array(
				'pname' => "NOKIA 5800",
				'price' => "2000",
				),
				);
	echo "遍历二维数组："."<br/>";
	foreach ($result as $product_k => $product_v) {
		foreach ($product_v as $key => $value) {
			echo $key.":".$value." ";
		}
			echo "<br/>";
		}echo "<br/>";	
	echo "使用explode将字符串转成数组："."<br/>";
	$StrNumber = "1,2,3,4,5,6";
	$ArrStrNumber = explode(',',$StrNumber);
	print_r($ArrStrNumber);echo "<br/>";

	echo "使用implode将数组转成字符串："."<br/>";
	$Arrstr = array('a','b','c','d','e');
	$str = implode('|',$Arrstr);
	echo $str."<br/>";

	/*练习*/
	$week1 = array('Monday','Tuesday','3'=>'Wednesday');
	echo $week1['3'];
?>
