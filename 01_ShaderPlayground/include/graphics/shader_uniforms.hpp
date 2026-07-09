#pragma once

#include <graphics/shader.hpp>
#include <glm/glm.hpp>

struct ShaderUniforms {
    float Time = 0.0f;
    float Intensity = 1.0f;
    glm::vec3 Color{1.0f};

    void Apply(Shader& shader) const {
        if (shader.UniformExists("uTime")) shader.SetFloat("uTime", Time);
        if (shader.UniformExists("uIntensity")) shader.SetFloat("uIntensity", Intensity);
        if (shader.UniformExists("uColor")) shader.SetVec3("uColor", Color);
    }
};