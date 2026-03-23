#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/modify/PauseLayer.hpp>
class $modify(myPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto normalBarParent = this->getChildByID("normal-progress-bar");
        if (!normalBarParent) return;
        auto normalBar = static_cast<CCSprite*>(normalBarParent->getChildren()->objectAtIndex(0));
        if (!normalBar) return;
        
        auto practiceBarParent = this->getChildByID("practice-progress-bar");
        if (!practiceBarParent) return;
        auto practiceBar = static_cast<CCSprite*>(practiceBarParent->getChildren()->objectAtIndex(0));
        if (!practiceBar) return;


        const float maxProgressWidth = 340.f; // practice and normal bar are same size
        const float maxProgressHeight = 20.f;
        const float minProgressHeight = 0.f;
        
        auto normalRect = normalBar->getTextureRect();
        auto practiceRect = practiceBar->getTextureRect();

        float normalProgress = normalRect.size.width / maxProgressWidth;
        float adjustedNormalProgress = minProgressHeight + (normalProgress) * (maxProgressHeight-minProgressHeight);
        
        float practiceProgress = practiceRect.size.width / maxProgressWidth; 
        float adjustedPracticeProgress = minProgressHeight + (practiceProgress) * (maxProgressHeight-minProgressHeight);

        normalBar->setAnchorPoint(CCPoint(0, 0));
        normalBar->setFlipY(true);
        normalBar->setPosition(CCPoint(0, 0));

        practiceBar->setAnchorPoint(CCPoint(0, 0));
        practiceBar->setFlipY(true);
        practiceBar->setPosition(CCPoint(0, 0)); 
        
        normalBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedNormalProgress)); 
        practiceBar->setTextureRect(CCRect(0, 0, maxProgressWidth, adjustedPracticeProgress)); 
    }
};