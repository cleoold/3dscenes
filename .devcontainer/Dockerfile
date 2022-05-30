# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.233.0/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version (use ubuntu-22.04 or ubuntu-18.04 on local arm64/Apple Silicon): ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="jammy"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# install packages
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    xz-utils \
    gcc \
    g++ \
    make \
    cmake \
    vim

ENV USER=vscode
USER ${USER}
WORKDIR /home/${USER}
RUN pwd
# install emcc sdk
# per https://emscripten.org/docs/getting_started/downloads.html
RUN git clone https://github.com/emscripten-core/emsdk.git
RUN cd emsdk \
    && ./emsdk install latest \
    && ./emsdk activate latest

# config emcc command at start up
RUN printf "\n# emcc command\nsource $(pwd)/emsdk/emsdk_env.sh\n" >> ~/.bashrc
