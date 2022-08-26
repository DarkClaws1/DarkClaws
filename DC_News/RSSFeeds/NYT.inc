[Variables]
mainURL=http://nytimes.com
URL=http://rss.nytimes.com/services/xml/rss/nyt/World.xml
storysect=<item>.*<title>(.*)</title>.*<link>(.*)</link>.*url="(.*)".*</item>.*
Captures=3
TitleIndex=-2
LinkIndex=-1
ImageIndex=0



