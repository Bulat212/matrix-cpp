FROM ubuntu:latest

# Обновление и установка пакетов в одном RUN для уменьшения слоев
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    gcc \
    valgrind \
    libgtest-dev \
    make \
    vim \
    check \
    clang-format \
    lcov \
    gcovr \
    git \
    curl \
    zsh \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /project
COPY . .

CMD ["zsh"]