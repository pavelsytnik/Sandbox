#ifndef STATE_HPP
#define STATE_HPP

class State {

public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual ~State() = 0;
};

#endif
