#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT

#include "Import.h"

Importer::Importer(std::string filename)
{
    std::string error;
    std::string warning;
    tinygltf::Model model;
    tinygltf::TinyGLTF loader;

    bool loaded = loader.LoadASCIIFromFile(&model, &error, &warning, filename);

    if (!warning.empty()) {
        printf("Warn: %s\n", warning.c_str());
    }

    if (!warning.empty()) {
        printf("Err: %s\n", error.c_str());
    }

    if (!loaded) {
        printf("Failed to parse glTF\n");
    }
}