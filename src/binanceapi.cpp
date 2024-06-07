/* 
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

class BinanceAPI {
private:
    CURL* curl;
    std::string* readBuffer;

    // Função callback para o cURL escrever os dados recebidos em uma string
    static size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* s)
    {
        s->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

public:
    BinanceAPI() : curl(curl_easy_init()), readBuffer(new std::string) {}

    ~BinanceAPI() {
        if (curl) {
            curl_easy_cleanup(curl);
        }
        delete readBuffer;
    }

    std::string getPrice(const std::string& symbol) {
        if (!curl) {
            return "Erro ao inicializar cURL";
        }

        std::string url = "https://api.binance.com/api/v3/ticker/price?symbol=" + symbol;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            return "Falha na requisição: " + std::string(curl_easy_strerror(res));
        }

        Json::Value root;
        Json::Reader reader;
        bool parsedSuccess = reader.parse(*readBuffer, root);
        if (!parsedSuccess) {
            return "Falha ao fazer o parse do JSON";
        }

        // Limpar o buffer após o uso
        std::string price = root["price"].asString();
        readBuffer->clear();

        return price;
    }
};

int main() {
    BinanceAPI api;
    
    Switch ()
    std::string symbol = "BTCUSDT";
    std::string price = api.getPrice(symbol);
    std::cout << "Preço do " << symbol << ": " << price << std::endl;

    return 0;
}
*/