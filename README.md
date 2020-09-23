# ESP32_Async_Download_File_From_SD_Card
ESP32 Asenkron Web Server'a /download adresine GET isteğinde bulunulduğunda SD kart modülünden istediğiniz dosyaya erişip cihazınıza indirmenizi sağlar.
Eğer dosyayı indirmeyi başaramadıysanız SD kartı sonlandırıp başlatın. Yani SD.end() ve SD.begin() fonksiyonlarını çağırın. Bu sayede dosyayı indirmiş olacaksınız.
