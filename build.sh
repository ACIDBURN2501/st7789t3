#!/bin/bash
set -e

BUILD_DIR="build"
PREFIX="/usr/local"

case "$1" in
  setup)
    meson setup "$BUILD_DIR" --prefix="$PREFIX" --buildtype=release
    ;;
  build)
    meson compile -C "$BUILD_DIR"
    ;;
  test)
    meson test -C "$BUILD_DIR"
    ;;
  install)
    sudo meson install -C "$BUILD_DIR"
    ;;
  clean)
    rm -rf "$BUILD_DIR"
    ;;
  full)
    rm -rf "$BUILD_DIR"
    meson setup "$BUILD_DIR" --prefix="$PREFIX" --buildtype=release
    meson compile -C "$BUILD_DIR"
    meson test -C "$BUILD_DIR"
    ;;
  *)
    echo "Usage: $0 {setup|build|test|install|clean|full}"
    ;;
esac

  cross)
    meson setup build-rpi --cross-file cross/rpi_armv7.txt --prefix=/usr --buildtype=release
    meson compile -C build-rpi
    ;;

  deploy)
    if [ -f .env ]; then
      source .env
    else
      echo "Missing .env file with PI_HOST and PI_PATH"; exit 1
    fi
    echo "Deploying to $PI_HOST:$PI_PATH"
    rsync -avz build-rpi/display_driver "$PI_HOST:$PI_PATH/"
    rsync -avz assets/ "$PI_HOST:$PI_PATH/assets/"
    ;;
