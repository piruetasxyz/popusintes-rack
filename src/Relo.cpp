#include "Popusintes.hpp"

// modulo
struct ReloModule : Module
{
    enum ParamIds
    {
        PARAM_FRECUENCIA,
        NUM_PARAMS,
    };

    enum InputIds
    {
        NUM_INPUTS,
    };

    enum OutputIds
    {
        SALIDA_RELOJ,
        NUM_OUTPUTS,
    };

    enum LightsIds
    {
        NUM_LIGHTS,
    };

    ReloModule()
    {

        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        configParam(PARAM_FRECUENCIA, 0.1f, 100.f, 0.f, "");
    }

    void process(const ProcessArgs &args) override
    {
        ;
    }
};

// widget
struct ReloModuleWidget : ModuleWidget
{
    ReloModuleWidget(ReloModule *module)
    {

        setModule(module);
        setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/ReloModule.svg")));

        // tornillos
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        // params
        addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(25.4 * 0.5, 128.4 * 0.40)), module, ReloModule::PARAM_FRECUENCIA));

        //  salidas
        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(25.4 * 0.5, 128.4 * 0.75)), module, ReloModule::SALIDA_RELOJ));
    }
};

Model *modelRelo = createModel<ReloModule, ReloModuleWidget>("relo");