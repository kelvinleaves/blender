#pragma once

#include "BKE_image.h"
#include "IMB_imbuf_types.h"

#include "particle_function.hpp"

namespace BParticles {

class AttributeInputProvider : public ParticleFunctionInputProvider {
 private:
  AttributeType m_type;
  std::string m_name;

 public:
  AttributeInputProvider(AttributeType type, StringRef name) : m_type(type), m_name(name)
  {
  }

  Optional<ParticleFunctionInputArray> get(InputProviderInterface &interface) override;
};

class CollisionNormalInputProvider : public ParticleFunctionInputProvider {
  Optional<ParticleFunctionInputArray> get(InputProviderInterface &interface) override;
};

class AgeInputProvider : public ParticleFunctionInputProvider {
  Optional<ParticleFunctionInputArray> get(InputProviderInterface &interface) override;
};

class SurfaceImageInputProvider : public ParticleFunctionInputProvider {
 private:
  Image *m_image;
  ImageUser m_image_user;
  ImBuf *m_ibuf;

 public:
  SurfaceImageInputProvider(Image *image);
  ~SurfaceImageInputProvider();

  Optional<ParticleFunctionInputArray> get(InputProviderInterface &interface) override;
};

class VertexWeightInputProvider : public ParticleFunctionInputProvider {
 private:
  std::string m_group_name;

 public:
  VertexWeightInputProvider(StringRef group_name) : m_group_name(group_name)
  {
  }

  Optional<ParticleFunctionInputArray> get(InputProviderInterface &interface) override;
};

}  // namespace BParticles
