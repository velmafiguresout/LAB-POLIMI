#LAB 1
# bir internet sitesinin home page'ini yüklerken server'ın cevap verme süresini çekmek (HTTP request)

import requests
import matplotlib.pyplot as plt #grafik çizmek istersem

sito = "http://www.google.com" #get requesti yapacağım sitenin url'si
r = requests.get(sito) #get request yapıyorum
print("tempo di risposta: ", r.elapsed.microseconds/1000, "ms")

#terminal çıktısı:
#tempo di risposta:  179.317 ms

for i in range (10): #for döngüsüyle 10 kere süreyi print ettim.
    r = requests.get(sito)
    print("tempo di risposta: ", r.elapsed.microseconds/1000, "ms")


# tempo di risposta:  94.211 ms
# tempo di risposta:  97.392 ms
# tempo di risposta:  96.424 ms
# tempo di risposta:  95.915 ms
# tempo di risposta:  96.258 ms
# tempo di risposta:  88.337 ms
# tempo di risposta:  88.425 ms
# tempo di risposta:  114.545 ms
# tempo di risposta:  83.074 ms
# tempo di risposta:  110.142 ms

#min, max ve avg hesaplamak istersem de
tempi = []
for i in range (10):
    r = requests.get(sito)
    tempi.append(r.elapsed.microseconds/1000)

print("tempo di risposta - MIN: ", min(tempi), "ms")
print("tempo di risposta - AVG: ", sum(tempi)/len(tempi), "ms")
print("tempo di risposta - MAX: ", max(tempi), "ms")

plt.figure() #grafik çizilmeden önce ilk figure oluşturulur, grafik çizilcek alan açılır.
plt.plot(tempi, label = f'{sito}', linestyle = "-.") #tempi listindeki süreleri x ekseninde 0'dan 9'a kadar indeksler. y eksenindeyse ms cinsinden yanıt sürelerini yerleştirir.
plt.ylim([0, 1.1 * max(tempi)]) #y ekseni 0'dan başlar, max yanut süresini 1.1'le çarparak grafiğin max noktasından biraz daha yukarıda bitmesini sağlar (grafik okunaklı olur).
plt.xlabel("ID richiesta") #x ekseninde gmsterilen her değer HTTP request olduğunu belirtir.
plt.ylabel("[ms]") #ms cinsinden değer karşılığı olduğunu belirtir.
plt.title(f"Test {sito}") #hangi siteye test yaptığımızı gösteren bir başlık atar. (f burda formatted string)
plt.grid() #grafiği gridli yapar.

#grafiği kaydetmek için:
nome_immagine = "%s.png" % sito [8:]
plt.savefig(nome_immagine)

plt.show() #çizilen grafiği gösterir.

print("#######################################################################")

#birden fazla siteden request çekmek istediğimizde:
siti = ["http://www.gazzetta.it", "http://www.netflix.com", "http://www.facebook.com"]
m = 0
plt.figure()
for url in siti:
    print(f"Test {url}")
    tempiM = []
    for i in range (10):
        r = requests.get(url)
        tempiM.append(r.elapsed.microseconds/1000)
    plt.plot(tempiM, label = url)
    print("tempo di risposta - MIN: ", min(tempiM), "ms")
    print("tempo di risposta - AVG: ", sum(tempiM) / len(tempiM), "ms")
    print("tempo di risposta - MIN: ", min(tempiM), "ms")
    m = max([m, max(tempiM)])

plt.ylim([0, 1.1 * m])
plt.xlabel("ID richiesta")
plt.ylabel("[ms]")
plt.title()


# PC'den Google server'ına nasıl bağlanılır?
# 1- PC'nin application layer'ı Google'ın server'ından home page'ini request eden GET isteğini oluşturur.
# Daha sonra veri PC'nin alt layerlarına iletilir.
# 2- Presentation layer veriyi sıkıştırma ve şifreleme (HTTPS durumunda) vs. işlemlerini yapar.
# 3- Session layerda oturum bilgileri eklenir (oturum id, çerezler vb.)
# 4- Transport layer'ında veri TCP protokolünü kullanarak TCP segmentlerine dönüştürür. Bu esnada da bağlantı ve paket kontrolü gerçekleşir.
# 4- Network layer'da TCP segmentleri IP paketlerine çevrilir. Google'ın server'ının IP adresine routerlarla yönlendirilir.
# 5- Data link layer'da IP paketleri MAC adresleri kullanılarak fiziksel ağ bağlantısı üzerinden gönderilir.
# 6- Physical layer'da veri fizilsel olarak (fiber optik kabloyla) Google'ın server'ına iletilir.

# 1- Request Google'ın server'ına ulaştığı an server'ın Physical layer'ı PC'ye respond gönderir.
#
