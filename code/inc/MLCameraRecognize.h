// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2018 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

// %SRC_VERSION%: 1

#include <lumin/LandscapeApp.h>
#include <lumin/Prism.h>
#include <lumin/event/ServerEvent.h>
#include <SceneDescriptor.h>
#include <PrismSceneManager.h>

/**
 * MLCameraRecognize Landscape Application
 */
class MLCameraRecognize : public lumin::LandscapeApp {
public:
  /**
   * Constructs the Landscape Application.
   */
  MLCameraRecognize();

  /**
   * Destroys the Landscape Application.
   */
  virtual ~MLCameraRecognize();

  /**
   * Disallows the copy constructor.
   */
  MLCameraRecognize(const MLCameraRecognize&) = delete;

  /**
   * Disallows the move constructor.
   */
  MLCameraRecognize(MLCameraRecognize&&) = delete;

  /**
   * Disallows the copy assignment operator.
   */
  MLCameraRecognize& operator=(const MLCameraRecognize&) = delete;

  /**
   * Disallows the move assignment operator.
   */
  MLCameraRecognize& operator=(MLCameraRecognize&&) = delete;

protected:
  /**
   * Initializes the Landscape Application.
   * @return - 0 on success, error code on failure.
   */
  int init() override;

  /**
   * Deinitializes the Landscape Application.
   * @return - 0 on success, error code on failure.
   */
  int deInit() override;

  /**
   * Returns the initial size of the Prism
   * Used in createPrism().
   */
  const glm::vec3 getInitialPrismSize() const;

  /**
   * Creates the prism, updates the private variable prism_ with the created prism.
   */
  void createInitialPrism();

  /**
   * Initializes and creates the scene of all scenes marked as initially instanced
   */
  void spawnInitialScenes();

  /**
   * Run application login
   */
  virtual bool updateLoop(float fDelta) override;

  /**
   * Handle events from the server
   */
  virtual bool eventListener(lumin::ServerEvent* event) override;

private:
  lumin::Prism* prism_ = nullptr;  // represents the bounded space where the App renders.
  PrismSceneManager* prismSceneManager_ = nullptr;
};

