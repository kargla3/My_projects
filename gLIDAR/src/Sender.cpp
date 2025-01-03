#include "Sender.h"

Sender::Sender() {}

void Sender::begin(String ssid, String password, int WiFiport)
{
    Serial.begin(921600);
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    port = WiFiport;
    udpClient.begin(port);
    int numClients;
    for (int i = 0; i < 5000; i++)
    {
        numClients = WiFi.softAPgetStationNum();
    }
    if (numClients > 0)
    {
        wifi_sta_list_t stationList;
        tcpip_adapter_sta_list_t adapterList;

        esp_wifi_ap_get_sta_list(&stationList);
        tcpip_adapter_get_sta_list(&stationList, &adapterList);

        for (int i = 0; i < adapterList.num; i++)
        {
            tcpip_adapter_sta_info_t station = adapterList.sta[i];

            Serial.print("Klient ");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(IPAddress(station.ip.addr));
        }
    }
}

void Sender::checkIPs()
{
    clients.clear();
    wifi_sta_list_t stationList;
    tcpip_adapter_sta_list_t adapterList;

    esp_wifi_ap_get_sta_list(&stationList);
    tcpip_adapter_get_sta_list(&stationList, &adapterList);

    for (int i = 0; i < adapterList.num; i++)
    {
        tcpip_adapter_sta_info_t station = adapterList.sta[i];
        clients.push_back(station.ip.addr);
    }
}

void Sender::sendParameters(String data)
{
    if (clients.size() > 0)
        for (IPAddress ip : clients)
        {
            udpClient.beginPacket(ip, port);
            udpClient.print(data);
            if (udpClient.endPacket() == 1)
                Serial.println("Data sent!");
            else
                Serial.println("Error in sending data");
        }
    else
        Serial.println(data);
}