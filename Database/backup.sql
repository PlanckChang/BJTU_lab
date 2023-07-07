-- MySQL dump 10.13  Distrib 8.0.33, for Win64 (x86_64)
--
-- Host: localhost    Database: appdb
-- ------------------------------------------------------
-- Server version	8.0.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `admin` (
  `username` char(15) NOT NULL,
  `password` char(32) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES ('root','63a9f0ea7bb98050796b649e85481845');
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `username` char(15) NOT NULL,
  `password` char(32) NOT NULL,
  `address` char(50) NOT NULL,
  `phone` char(15) NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('David','098f6bcd4621d373cade4e832627b4f6','22号楼','123124214'),('hello','098f6bcd4621d373cade4e832627b4f6','嘉园B座','232141214'),('lonelyprince7','30e535568de1f9231e7d9df0f4a5a44d','西南石油大学学生宿舍10-222','13844444444'),('nobody','4297f44b13955235245b2497399d7a93','19号楼','12312412'),('test','098f6bcd4621d373cade4e832627b4f6','北京交通大学主校区','1232141124'),('你好','098f6bcd4621d373cade4e832627b4f6','嘉园','1253532'),('小张','0584c797130f5bd8695531213f890b9a','西南石油大学学生宿舍17-555','18833344444');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dishes`
--

DROP TABLE IF EXISTS `dishes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `dishes` (
  `dishname` char(15) NOT NULL,
  `restaurant` char(15) NOT NULL,
  `dishinfo` varchar(50) DEFAULT NULL,
  `nutriention` varchar(30) DEFAULT NULL,
  `price` decimal(5,2) NOT NULL,
  `sales` int NOT NULL,
  `imgsrc` varchar(50) DEFAULT NULL,
  `isSpecialty` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`dishname`),
  KEY `restaurant` (`restaurant`),
  CONSTRAINT `dishes_ibfk_1` FOREIGN KEY (`restaurant`) REFERENCES `restaurant` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dishes`
--

LOCK TABLES `dishes` WRITE;
/*!40000 ALTER TABLE `dishes` DISABLE KEYS */;
INSERT INTO `dishes` VALUES ('大盘鸡','土风土味','好吃','蛋白质',44.00,2,'static/images/jpg',0),('好吃不腻的菜','土风土味','好吃','好吃',32.00,1,'static/images/img_4.jpg',0),('很好','土风土味','不错','好',342.00,1,'static/images/disanxian.jpg',0),('水煮鱼','土风土味','松江鲈鱼，巨口细鳞，肉质鲜嫩','蛋白质，维生素',26.00,8,'static/images/img_2.jpg',0),('牛肉面','统一面馆','老坛酸菜牛肉面，麻辣酸爽，美味享受','蛋白质，淀粉，维生素',13.00,1,'static/images/img_7.jpg',0),('香锅牛肉','土风土味','该香锅牛肉味道鲜美，有土豆藕片等蔬菜可添加','蛋白质，维生素',14.50,0,'static/images/img_5.jpg',1);
/*!40000 ALTER TABLE `dishes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order_comment`
--

DROP TABLE IF EXISTS `order_comment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `order_comment` (
  `orderID` int NOT NULL AUTO_INCREMENT,
  `username` char(15) NOT NULL,
  `dishname` char(30) DEFAULT NULL,
  `restaurant` varchar(15) NOT NULL,
  `isFinished` tinyint(1) DEFAULT '0',
  `cost` decimal(5,2) NOT NULL,
  `c_rank` int DEFAULT NULL,
  `text` varchar(50) DEFAULT NULL,
  `transactiontime` timestamp NOT NULL,
  `comment_time` timestamp NULL DEFAULT NULL,
  `img_src` char(50) DEFAULT NULL,
  PRIMARY KEY (`orderID`),
  KEY `username` (`username`),
  KEY `restaurant` (`restaurant`),
  CONSTRAINT `order_comment_ibfk_1` FOREIGN KEY (`username`) REFERENCES `customer` (`username`),
  CONSTRAINT `order_comment_ibfk_2` FOREIGN KEY (`restaurant`) REFERENCES `restaurant` (`username`),
  CONSTRAINT `c_rank_check` CHECK ((`c_rank` between 0 and 10)),
  CONSTRAINT `order_comment_chk_1` CHECK (((`isFinished` = 1) or (`isFinished` = 0))),
  CONSTRAINT `order_comment_chk_2` CHECK ((`c_rank` between 1 and 5)),
  CONSTRAINT `order_comment_chk_3` CHECK ((`transactiontime` between _utf8mb4'1970-01-01 00:00:01' and _utf8mb4'2038-01-19 03:14:07'))
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_comment`
--

LOCK TABLES `order_comment` WRITE;
/*!40000 ALTER TABLE `order_comment` DISABLE KEYS */;
INSERT INTO `order_comment` VALUES (1,'test',NULL,'土风土味',1,26.00,NULL,'','2023-06-29 02:20:42',NULL,NULL),(2,'test','水煮鱼','土风土味',1,26.00,4,'好吃','2023-06-29 03:27:04',NULL,NULL),(3,'test','水煮鱼','土风土味',1,26.00,1,'感觉不好吃','2023-06-29 03:28:04','2023-06-29 15:40:05',NULL),(4,'test','水煮鱼','土风土味',1,26.00,NULL,'','2023-06-29 03:30:21',NULL,NULL),(6,'test','水煮鱼','土风土味',1,26.00,NULL,'','2023-06-29 03:31:25',NULL,NULL),(7,'test','水煮鱼','土风土味',1,26.00,3,'好吃','2023-06-29 03:45:23',NULL,NULL),(8,'test','水煮鱼','土风土味',1,26.00,NULL,'','2023-06-29 03:45:26',NULL,NULL),(9,'test','水煮鱼','土风土味',1,26.00,NULL,'','2023-06-29 03:49:09',NULL,NULL),(10,'test','水煮鱼','土风土味',0,26.00,NULL,NULL,'2023-06-29 03:49:12',NULL,NULL),(11,'test','水煮鱼','土风土味',0,26.00,NULL,NULL,'2023-06-29 04:14:22',NULL,NULL),(12,'test','水煮鱼','土风土味',1,26.00,5,'很好','2023-06-29 04:16:12',NULL,NULL),(13,'test','大盘鸡','土风土味',1,44.00,NULL,'','2023-06-29 14:36:06',NULL,'static/images/jpg'),(14,'test','水煮鱼','土风土味',0,26.00,NULL,NULL,'2023-06-29 14:41:06',NULL,'static/images/img_2.jpg'),(15,'test','大盘鸡','土风土味',0,44.00,NULL,NULL,'2023-06-29 14:46:50',NULL,'static/images/jpg'),(16,'test','大盘鸡','土风土味',0,44.00,NULL,NULL,'2023-06-29 14:53:36',NULL,'static/images/jpg'),(17,'test','大盘鸡','土风土味',1,44.00,NULL,'','2023-06-29 14:53:40',NULL,'static/images/jpg'),(18,'test','好吃不腻的菜','土风土味',1,323.00,3,'不怎好吃','2023-06-30 08:07:40','2023-06-30 08:08:27','static/images/jpg'),(19,'test','很好','土风土味',1,342.00,3,'好','2023-06-30 10:34:25','2023-06-30 10:35:11','static/images/disanxian.jpg');
/*!40000 ALTER TABLE `order_comment` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = gbk */ ;
/*!50003 SET character_set_results = gbk */ ;
/*!50003 SET collation_connection  = gbk_chinese_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `update_sales_trigger` AFTER UPDATE ON `order_comment` FOR EACH ROW BEGIN
    DECLARE order_restaurant CHAR(30);
    DECLARE order_dishname CHAR(30);
    
    IF NEW.isFinished = 1 and OLD.isFinished = 0 THEN
        

        SELECT restaurant, dishname INTO order_restaurant, order_dishname FROM ORDER_COMMENT WHERE orderID = NEW.orderID;

        
        UPDATE DISHES SET sales = sales + 1 WHERE dishname = order_dishname AND restaurant = order_restaurant;
    END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `restaurant`
--

DROP TABLE IF EXISTS `restaurant`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `restaurant` (
  `username` char(15) NOT NULL,
  `password` char(32) NOT NULL,
  `address` varchar(30) NOT NULL,
  `phone` char(15) NOT NULL,
  `img_res` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `restaurant`
--

LOCK TABLES `restaurant` WRITE;
/*!40000 ALTER TABLE `restaurant` DISABLE KEYS */;
INSERT INTO `restaurant` VALUES ('RestaurantTest','098f6bcd4621d373cade4e832627b4f6','交大南门1号','1214144342','None'),('test2','098f6bcd4621d373cade4e832627b4f6','学生一餐厅','12321412',NULL),('一点点','cd6a1a15421189de23d7309feebff8d7','红果园','213123','没有图片'),('土风土味','098f6bcd4621d373cade4e832627b4f6','','','static/images/res_2.jpg'),('瑞幸','fd45ebc1e1d76bc1fe0ba933e60e9957','3434','43242','43434'),('瑞鑫','fb2e636577105f243646d6f1e199f0ba','红果园一楼','12312312','无'),('统一面馆','098f6bcd4621d373cade4e832627b4f6','东直门一号院','','static/images/res_1.jpg');
/*!40000 ALTER TABLE `restaurant` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `restaurant_order_view`
--

DROP TABLE IF EXISTS `restaurant_order_view`;
/*!50001 DROP VIEW IF EXISTS `restaurant_order_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `restaurant_order_view` AS SELECT 
 1 AS `orderID`,
 1 AS `username`,
 1 AS `dishname`,
 1 AS `restaurant`,
 1 AS `isFinished`,
 1 AS `cost`,
 1 AS `c_rank`,
 1 AS `text`,
 1 AS `transactiontime`,
 1 AS `comment_time`,
 1 AS `img_src`,
 1 AS `address`,
 1 AS `phone`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `shoppingcart`
--

DROP TABLE IF EXISTS `shoppingcart`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shoppingcart` (
  `username` char(15) NOT NULL,
  `restaurant` char(15) NOT NULL,
  `dishname` char(15) NOT NULL,
  `price` decimal(5,2) NOT NULL,
  `img_res` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`username`,`restaurant`,`dishname`),
  KEY `restaurant` (`restaurant`),
  KEY `dishname` (`dishname`),
  CONSTRAINT `shoppingcart_ibfk_1` FOREIGN KEY (`username`) REFERENCES `customer` (`username`),
  CONSTRAINT `shoppingcart_ibfk_2` FOREIGN KEY (`restaurant`) REFERENCES `restaurant` (`username`),
  CONSTRAINT `shoppingcart_ibfk_3` FOREIGN KEY (`dishname`) REFERENCES `dishes` (`dishname`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shoppingcart`
--

LOCK TABLES `shoppingcart` WRITE;
/*!40000 ALTER TABLE `shoppingcart` DISABLE KEYS */;
INSERT INTO `shoppingcart` VALUES ('test','土风土味','水煮鱼',26.00,'static/images/img_2.jpg'),('test','土风土味','香锅牛肉',14.50,'static/images/img_5.jpg');
/*!40000 ALTER TABLE `shoppingcart` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `restaurant_order_view`
--

/*!50001 DROP VIEW IF EXISTS `restaurant_order_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = gbk */;
/*!50001 SET character_set_results     = gbk */;
/*!50001 SET collation_connection      = gbk_chinese_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `restaurant_order_view` AS select `order_comment`.`orderID` AS `orderID`,`order_comment`.`username` AS `username`,`order_comment`.`dishname` AS `dishname`,`order_comment`.`restaurant` AS `restaurant`,`order_comment`.`isFinished` AS `isFinished`,`order_comment`.`cost` AS `cost`,`order_comment`.`c_rank` AS `c_rank`,`order_comment`.`text` AS `text`,`order_comment`.`transactiontime` AS `transactiontime`,`order_comment`.`comment_time` AS `comment_time`,`order_comment`.`img_src` AS `img_src`,`customer`.`address` AS `address`,`customer`.`phone` AS `phone` from (`order_comment` join `customer`) where (`order_comment`.`username` = `customer`.`username`) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-06-30 19:34:35
