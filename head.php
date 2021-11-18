<?php

session_start(); // 세션

if($_SESSION['id'] != null)
    $is_login = true;
 
?>

<!DOCTYPE html>
<html lang="en">

<head>
   

    <meta name="viewport" content="width=device-width,initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0">
    <meta name="format-detection" content="telephone=no">
    <meta name="author" content="anysecure">
    <meta name="robots" content="index, follow">

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <!-- 네이버 태그 -->
    <meta name="naver-site-verification" content="2f15a2c2af13d3a4b3d6fc5814a2b9f41a4d3e6d" />
    <meta name="naver-site-verification" content="1d27919542de45fe0c692e1ad28e9349dec12098" />
    <meta name="description" content="오피셜사이트! 누구나 나만의 공식홈페이지">
    <meta name="keywords"
        content="오피셜사이트,officialsite,무료도메인,무료 도메인, 도메인, 웹호스팅, 이미지 호스팅, 웹빌더, 서버 호스팅, 웹메일, SSL, 호스팅, 서버, IDC, 홈페이지 빌더, 코로케이션, 무료 홈페이지, 무료 호스팅, 메일 호스팅, 보안 인증서">


    <meta name="twitter:card" content="summary">
    <meta name="twitter:title" content="오피셜사이트">
    <meta name="twitter:description" content="오피셜사이트! 누구나 나만의 공식홈페이지">
    <meta name="twitter:image" content="http://officialsite.kr/static/images/free-domain.jpg">
    <meta name="twitter:domain" content="http://officialsite.kr"> 

    <meta property="og:title" content="오피셜사이트"> 
    <meta property="og:url" content="http://officialsite.kr">
    <meta property="og:type" content="website">
    <meta property="og:description" content="오피셜사이트! 누구나 나만의 공식홈페이지">
    <meta property="og:site_name" content="오피셜사이트">
    <meta property="og:image" content="http://officialsite.kr/static/images/free-domain.jpg"> 
    <meta property="og:image:alt" content="오피셜 사이트로 이동"> 
    <meta property="og:image:width" content="1200">
    <meta property="og:image:height" content="630"> 

    <!-- <meta name="viewport" content="width=device-width,initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0">
    <meta name="format-detection" content="telephone=no">
    <meta name="author" content="anysecure">
    <meta name="robots" content="index, follow">
    <meta name="description"
        content="오피셜사이트는 도메인, 무료 웹호스팅, 웹빌더, 메일호스팅, SSL보안인증서,  서버호스팅, 코로케이션 등 다양한 호스팅 서비스를 제공하고 있습니다.">
    <meta name="keywords"
        content="오피셜사이트,dothome, 도메인, 웹호스팅, 이미지 호스팅, 웹빌더, 서버 호스팅, 웹메일, SSL, 호스팅, 서버, IDC, 홈페이지 빌더, 코로케이션, 무료 홈페이지, 무료 호스팅, 메일 호스팅, 보안 인증서">

    <meta property="og:type" content="website">
    <meta property="og:title" content="오피셜사이트 | 호스팅은 오피셜사이트">
    <meta property="og:description"
        content="오피셜사이트는 도메인, 무료 웹호스팅, 웹빌더, 메일호스팅, SSL보안인증서,  서버호스팅, 코로케이션 등 다양한 호스팅 서비스를 제공하고 있습니다.">
    <meta property="og:image" content="https://officialsite.kr/static/images/free-domain.jpg">
    <meta property="og:image:width" content="1200">
    <meta property="og:image:height" content="630">

    <meta property="og:url" content="https://officialsite.kr/index.php"> -->



    <title>오피셜사이트 | 호스팅은 오피셜사이트</title>
    <link rel="shortcut icon" href="/asset/css/images/common/top/dothome.ico">
    <!-- Bootstrap core CSS -->
    <link href="/asset/css/bootstrap.min.css" rel="stylesheet">
    <link href="/asset/css/style.css" rel="stylesheet">
    <!--Font Awesome--><link href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">
    <!--Nav css-->
    <link href="/asset/css/justified-nav.css" rel="stylesheet">


    <!--Naver Search Advisor-->
    <link rel="canonical" href="https://officialsite.kr">

    <link rel="stylesheet" type="text/css" href="/asset/css//indexlayout.css">
    <link href="/asset/css/layout.css" rel="stylesheet">
    <link href="/asset/css/page.css" rel="stylesheet">
    <link href="/asset/css/mediaquery.css" rel="stylesheet">
    <link href="/asset/css/m-menu.css" rel="stylesheet">


    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script type="text/javascript" src="/asset/js/jquery.min.js"></script>
    <script type="text/javascript" src="/asset/js/jquery-ui.min.js"></script>
    <!-- Latest compiled and minified JavaScript -->
    <script type="text/javascript" src="/asset/js/bootstrap.min.js"></script> 
    <script type="text/javascript" src="/asset/js/application.js"></script>
    <script type="text/javascript" src="/asset/js/global.js"></script>
    <script type="text/javascript" src="/asset/js/domain.js"></script>

    <!--<script src="/js/dh2015/dropzone.min.js"></script>-->
</head>
