template<typename TBlock>
TBlock& Registry::registerBlock(const TBlock& block) {
    _blockRegistry.push_back(std::make_unique<TBlock>(block));
    return static_cast<TBlock&>(*_blockRegistry.back());
}
