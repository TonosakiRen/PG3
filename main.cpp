#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>
#include <list>
#include <string>

int main() {

    enum stationEra {
        era1970 = 1970,
        era2019 = 2019,
        era2022 = 2022,
    };

    stationEra stationEra = era2022;

    std::list <const char*> stationNames = {
      "Tokyo",
      "Kanda",
      "Akihabara",
      "Okachimachi",
      "Ueno",
      "Uguisudani",
      "Nippori",
      "Nishinippori",
      "Tabata",
      "Komagome",
      "Sugamo",
      "Otsuka",
      "Ikebukuro",
      "Mejiro",
      "Takadanobaba",
      "Shin-Okubo",
      "Shinjuku",
      "Yoyogi",
      "Harajuku",
      "Shibuya",
      "Ebisu",
      "Meguro",
      "Gotanda",
      "Osaki",
      "Shinagawa",
      "TakanawaGateway",
      "Tamachi",
      "Hamamatsucho",
      "Shimbashi",
      "Yurakucho"
    };
    while (true) {
        std::cout << "•\Ž¦‚·‚é”N‘ã‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(1970,2019,2022)" << std::endl;
        int era = 0;
        scanf_s("%d", &era);
        bool correctEra = true;
        switch (era)
        {
        case era1970:
        {
            auto it = std::find(stationNames.begin(), stationNames.end(), "Nishinippori");
            if (it != stationNames.end()) {
                stationNames.erase(it);
            }
            it = std::find(stationNames.begin(), stationNames.end(), "TakanawaGateway");
            if (it != stationNames.end()) {
                stationNames.erase(it);
            }
        }
            break;
        case era2019:
        {
            auto it = std::find(stationNames.begin(), stationNames.end(), "Nishinippori");
            if (it == stationNames.end()) {
                it = std::find(stationNames.begin(), stationNames.end(), "Nippori");
                stationNames.insert(it, "Nishinippori");
            }
            it = std::find(stationNames.begin(), stationNames.end(), "TakanawaGateway");
            if (it != stationNames.end()) {
                stationNames.erase(it);
            }
        }
            break;
        case era2022:
        {
            auto it = std::find(stationNames.begin(), stationNames.end(), "Nishinippori");
            if (it == stationNames.end()) {
                it = std::find(stationNames.begin(), stationNames.end(), "Nippori");
                stationNames.insert(it, "Nishinippori");
            }
            it = std::find(stationNames.begin(), stationNames.end(), "TakanawaGateway");
            if (it == stationNames.end()) {
                it = std::find(stationNames.begin(), stationNames.end(), "Shinagawa");
                stationNames.insert(it, "TakanawaGateway");
            }
        }
            break;
        default:
            correctEra = false;
            break;
        }

        if (correctEra) {
            for (const auto& name : stationNames) {
                std::wcout << name << std::endl;
            }
        }

    }

	return 0;
}

