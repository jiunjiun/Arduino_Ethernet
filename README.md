Arduino_Ethernet
====

[Blogger](http://jiun-blog.blogspot.tw/2013/05/arduino-ethernet_15.html)

要注意幾個，宣告幾個變數
- mac         為你設備的mac號
- ip            你這台Ethernet的ip你可以自行設定(網段要一樣才收得到, ip不可跟其他設備衝突)
- remote    你想要傳送的ip位置
- Listen(x) 你x可以設定你想監聽的port號


###EthernetSend()    -  傳送到指定位置##
- Deliver()：
client.print("GET /");
要設在client起始接著GET /斜線後面接你的目標網址
例如你可以設定成
        
        client.print("GET /save.php?a=123&b=456");

###EthernetListen()  -  監聽目標
- 當去瀏覽這個網頁就會啟動function
裡面的Request為回傳網頁資訊包含瀏覽的路徑, get/post, ....
- 接下的Control是針對瀏覽路徑知道要怎麼Control 設備(LED亮/滅)


# Copyright / License
* Copyright (c) 2013 jiunjiun (quietmes At gmail.com)
* Licensed under [GPL](http://www.gnu.org/licenses/gpl.html) licenses.

