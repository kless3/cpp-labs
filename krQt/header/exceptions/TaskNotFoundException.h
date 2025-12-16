#pragma once

#include "AppException.h"

class TaskNotFoundException : public AppException {
public:
    explicit TaskNotFoundException(int taskId);
};

