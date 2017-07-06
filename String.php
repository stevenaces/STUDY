<?php
	$val = 'world';

	echo "hello ".$val.'<br/>';
	print('hello $val').'<br/>';
	print("hello $val").'<br/>';	//""和''区别	
	print "hello $val".'<br/>';		//和上一句的结果一样

	$str = "123 test";
	printf("整数:%d",$str);		//printf后面不能直接接换行符
	echo "<br/>";
	printf("浮点数：%.2f",$str);
	echo "<br/>";
	printf("字符型:%s",$str);
	echo "<br/>";
	//printf("二进制输出:%b",$str)
	$val2 = "使用sprintf函数输出：".sprintf("%d",$str);	//sprintf功能和printf相同，但是不能直接输出结果
	echo $val2.'<br/>';

	echo "使用strpos函数输出：".strpos($str, "e")."<br/>";
	echo "使用stripos函数输出：".stripos($str, "T")."<br/>";	//不区分大小写的查找

	$str2 = "test@163.com";
	$str3 = "test@163.com";
	//将某串字符替换成某串字符在某个字符串中；	
	$email = str_replace("t@", "(at)",$str2);	
	echo "使用str_replace函数输出：email=".$email."<br/>";
	$email2 = str_ireplace("TEST@","(at)" , $str3);
	echo "使用str_ireplace函数输出：email=".$email2."<br/>";

	//截取第二个参数之后的，包括第二个参数对应的字符
	echo "使用substr函数输出：".substr("Hello world",6)."<br/>";	
	//从第二个参数开始截取，截取的字符个数为第三个，str.length+1-第二参数-第三参数<0，返回值为空串；
	echo "使用substr函数有三参数的输出：".substr("Hello world",6,5)."<br/>";
	//返回从匹配点开始的后续字符串，没有匹配到，放回false
	echo "使用strstr函数的输出：".strstr("Hello world,你好世界", "world")."<br/>";
	//返回从匹配点开始的后续字符串,不区分大小写
	echo "使用stristr函数的输出：".stristr("Hello WORLD,你好世界", "world")."<br/>";

	echo "使用ltrim函数的输出：".ltrim("从此有空格——>|      hello world   |<——")."<br/>";
	echo "使用rtrim函数的输出：".rtrim("hello world   |<——")."<br/>";
	echo "使用trim函数的输出：".trim("从此有空格——>|      hello world   |<——")."<br/>";

	/*其它字符串处理函数*/
	$passwd = "123456";
	if(strlen($passwd)<8){
		echo "密码不能少于8位"."<br/>";
	}

	$url1 = "HTTP://WWW.BAIDU.COM";
	echo strtolower($url1)."<br/>";

	$url2 = "http://www.baidu.com";
	echo strtoupper($url2)."<br/>";

	echo "中文hello world"."<br/>";
	echo "使用strrev函数的输出：".strrev("中文hello world")."<br/>";

	$str4 = "hello
	world";
	echo nl2br($str4)."<br/>";

	$str5 = "test<a href='http://www.163.com'>163</a>";
	echo $str5."<br/>";
	echo "使用strip_tags函数的输出：".strip_tags($str5)."<br/>";

	$str6 = "<p>这是一个段落</p>&#65;";
	echo $str6;
	echo "使用htmlspecialchars函数的输出：".htmlspecialchars($str6)."<br/>";
	/*练习题*/
	$a = "PHPlinux";
	$b = "PHPLinux";
	$c = strstr($a, 'L');
	$d = stristr($b, 'l');
	echo $c."is".$d."<br/>";

	$first = "This course is very easy!";
	$second = explode(" ",$first);
	var_dump($second);
	$first = implode(",",$second);
	echo $first."<br/>";

	$email3 = "abc@test.com.cn";
	$str7 = strstr($email3,'@');
	$info = explode('.',$str7);
	var_dump($info)."<br/>";

?>
