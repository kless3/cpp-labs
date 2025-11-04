//
// Created by Maksim on 04.11.2025.
//

#include "../include/NotFoundException.h"

NotFoundException::NotFoundException(const std::string& message)
        : std::runtime_error(message) {}