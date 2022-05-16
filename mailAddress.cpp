// Copyright (c) 2022 Peter Gemmell All rights reserved

// Created by Peter Gemmell
// Created on May 2022
// This program format the mailing adress

#include <iostream>
#include <string>
#include <algorithm>

std::string formatAddress(
    std::string fullName,
    std::string houseNumber,
    std::string streetName,
    std::string cityName,
    std::string provinceName,
    std::string postalCode,
    std::string apartmentNumber = "") {

    // format address
    std::string address;

    // process
    if (apartmentNumber == "") {
        std::string line1 = fullName + "\n";
        std::string line2 = houseNumber + " " + streetName + "\n";
        std::string line3 = cityName + " " + provinceName + "  " + postalCode;
        address = line1 + line2 + line3;

    } else {
        std::string line1 = fullName + "\n";
        std::string line2 = apartmentNumber + " - " + houseNumber  + " " +
        streetName + "\n";
        std::string line3 = cityName + " " + provinceName + "  " + postalCode;
        address = line1 + line2 + line3;
    }
    // https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    std::transform(address.begin(), address.end(), address.begin(), ::toupper);

    // output
    return address;
}

int main() {
    // this function gets the user input

    std::string fullName;
    std::string apartmentAnswer;
    std::string apartmentNumber;
    std::string houseNumber;
    std::string streetName;
    std::string cityName;
    std::string provinceName;
    std::string postalCode;
    std::string addressFormatted;
    int apartmentNumberAsInt;
    int houseNumberAsInt;
    std::string formattedAddress;

    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, fullName);
    std::cout << "Do you live in an apartment (y/n): ";
    getline(std::cin, apartmentAnswer);
        if ((apartmentAnswer == "y")
        || (apartmentAnswer == "yes")) {
            std::cout << "Enter your apartment number: ";
            getline(std::cin, apartmentNumber);
        } else {
            apartmentNumber = "";
        }
    std::cout << "Enter your house number: ";
    getline(std::cin, houseNumber);
    std::cout << "Enter your street name: ";
    getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    getline(std::cin, cityName);
    std::cout << "Enter your province (ON, CB): ";
    getline(std::cin, provinceName);
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCode);

    try {
        if ((apartmentAnswer == "y")
        || (apartmentAnswer == "yes")) {
            apartmentNumberAsInt = std::stoi(apartmentNumber);
            houseNumberAsInt = std::stoi(houseNumber);
            formattedAddress = formatAddress(
                fullName,
                houseNumber,
                streetName,
                cityName,
                provinceName,
                postalCode,
                apartmentNumber);
        } else {
            houseNumberAsInt = std::stoi(houseNumber);
            formattedAddress = formatAddress(
                fullName,
                houseNumber,
                streetName,
                cityName,
                provinceName,
                postalCode);
        }

        std::cout << "\n" << formattedAddress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid input response, please try again." << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
