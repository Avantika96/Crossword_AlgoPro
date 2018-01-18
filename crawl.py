import requests
from bs4 import BeautifulSoup

def word_crawler():
	f=open('list.txt','w')
	url="https://www.vocabulary.com/lists/52473"
	code=requests.get(url)
	text=code.text
	soup=BeautifulSoup(text)
	for words in soup.findAll('a',{'class':'word dynamictext'}):			
			full=words.string
			#print(full)
			f.write(full)
			f.write('\n')
	f.close()
		
word_crawler()
