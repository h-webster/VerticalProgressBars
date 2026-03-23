#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/modify/PlayLayer.hpp>
class $modify(myPlayLayer, PlayLayer) {
    void updateProgressbar() {
        PlayLayer::updateProgressbar();    
        
        auto progressBarParent = this->getChildByID("progress-bar");
        if (!progressBarParent) return;
        auto progressBar = static_cast<CCSprite*>(progressBarParent->getChildren()->objectAtIndex(0));
        if (!progressBar) return;

        const float maxProgressWidth = 206.f;
        const float maxProgressHeight = 6.6;
        const float minProgressHeight = 1.52f; 
        auto currentRect = progressBar->getTextureRect();
        float progress = currentRect.size.width / maxProgressWidth;
        float adjustedProgress = minProgressHeight + (progress) * (maxProgressHeight-minProgressHeight);
        progressBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedProgress)); 
     
    } 
};