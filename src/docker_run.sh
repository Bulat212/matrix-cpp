#!/bin/bash

# Настройка Docker для Mac (если нужно)
if [ "$(uname)" = "Darwin" ]; then
    rm -rf ~/Library/Containers/com.docker.docker
    mkdir -p ~/goinfre/Docker/Data
    ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker
    open /Applications/Docker.app
fi

# Ожидание запуска Docker
while ! docker info >/dev/null 2>&1; do
    echo "Waiting for Docker to start..."
    sleep 2
done

# Проверка и запуск контейнера
if [ "$(docker ps -aq -f name=ubuntu_dev)" ]; then
    echo "Starting existing container..."
    docker start -ai ubuntu_dev
else
    echo "Building new container..."
    docker build -t ubuntu_dev .
    docker run -it \
        --name ubuntu_dev \
        -v "$PWD:/project" \
        -w /project \
        ubuntu_dev
fi