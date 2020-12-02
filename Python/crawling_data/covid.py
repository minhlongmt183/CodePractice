from lxml import html
import csv
import os
import requests
from exceptions import ValueError
from time import sleep
from random import randint
 
def parse(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36'
    }
    
    try:
        # Retrying for failed requests
        for i in range(20):
            # Generating random delays
            sleep(randint(1,3))
            # Adding verify=False to avold ssl related issues
        cookies = { hRz0g1/U3dzTGO8FPnE2WLKFY17qm6gxQXkJ8FZciH2+miwwcuUjJ/YDaHVbpbVMaxvScguLCXBmN23uVB3xTj6iAGy35YhhEcpSoZ8PaAG/bbhHBUFRX70w1XAIAtl+s9ekX/IZBgbubg5rc55sl5eV/pl8f319xWV+RMC9UpoJ5UqMpUOIllcEOiErxBwmFGkAcfaXVxXNXCTxMebU1hStaQtQ75SnZaWWyn9bl8UU6nuAaUQuYVET86smuGR79Amx6QHxlgw=}
            response = requests.get(url, headers=headers, verify=False, cookies=cookies)
 
            if response.status_code == 200: 
                doc = html.fromstring(response.content)
                XPATH_NAME = '//h1[@id="title"]//text()'
                XPATH_PRICE = '//span[contains(@id,"priceblock_ourprice")]/text()'
 
                RAW_NAME = doc.xpath(XPATH_NAME)
                RAW_PRICE = doc.xpath(XPATH_PRICE)
 
                NAME = ' '.join(''.join(RAW_NAME).split()) if RAW_NAME else None
                PRICE = ' '.join(''.join(RAW_PRICE).split()).strip() if RAW_SALE_PRICE else None
 
                data = {
                    'NAME': NAME,
                    'PRICE': PRICE,
                    'URL': url,
                }
                return data
            
            elif response.status_code==404:
                break
 
    except Exception as e:
        print e

def ReadUrl():
    UrlList = ['https://www.amazon.com/Upgraded-Dimmable-Spectrum-Adjustable-Gooseneck/dp/B07PXP7DW5', 'https://www.amazon.com/Autel-MS906-Automotive-Diagnostic-Adaptations/dp/B01CQNNBA4?ref_=Oct_DLandingS_PC_b8ca5425_2&smid=A3MNQOSQ336D3K']
    extracted_data = []
 
    for i in UrlList:
        print "Processing: " + i
        # Calling the parser
        parsed_data = parse(i)
        if parsed_data:
            extracted_data.append(parsed_data)
 
    # Writing scraped data to csv file
    with open('scraped_data.csv', 'w') as csvfile:
        fieldnames = ['NAME','PRICE','URL']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames, quoting=csv.QUOTE_ALL)
        writer.writeheader()    
        for data in extracted_data:
            writer.writerow(data)
 
if __name__ == "__main__":
    ReadUrl()