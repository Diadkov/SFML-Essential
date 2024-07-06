#include "AssetManager.h" // Include header file for AssetManager class
#include "assert.h" // Include assert header for debugging
#include <iostream> // Include iostream for console output
#include <SFML/Graphics.hpp> // Include SFML graphics library

AssetManager* AssetManager::sInstance = nullptr; // Initialize static instance pointer

AssetManager::AssetManager() {
    assert(sInstance == nullptr); // Assert that the instance is not already initialized
    sInstance = this; // Set the static instance pointer to this instance
}

// Function to get a texture from the asset manager
sf::Texture& AssetManager::GetTexture(std::string const& filename) {
    auto& texMap = sInstance->m_Textures; // Reference to the textures map in the instance

    // Check if the texture already exists in the map
    auto pairFound = texMap.find(filename);

    if (pairFound != texMap.end()) {
        // If texture is found in map, print a message and return the existing texture
        std::cout << "Reusing texture: " << filename << std::endl;
        return pairFound->second;
    }
    else {
        // If texture is not found, load it from file, add to map, and return the new texture
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}