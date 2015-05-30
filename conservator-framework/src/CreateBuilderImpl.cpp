//
// Created by Ray Jenkins on 4/29/15.
//

#include <sstream>
#include "CreateBuilderImpl.h"

CreateBuilderImpl::CreateBuilderImpl(zhandle_t *zk) {
    this->zk = zk;
}

int CreateBuilderImpl::forPath(string path) {
    return this->forPath(path, NULL);
}

int CreateBuilderImpl::forPath(string path, char *data) {
    char buffer[512];
    int length;
    if (data == NULL) {
        length = -1;
    } else {
        length = char_traits<char>::length(data);
    }
    return zoo_create(this->zk, path.c_str(), data, length, &ZOO_OPEN_ACL_UNSAFE, 0, buffer, sizeof(buffer) - 1);
}