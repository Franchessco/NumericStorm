#pragma once

#include <numeric>

#include "../Parameters.hpp"
#include "../Bounds.hpp"
#include <vector>

namespace NumericStorm 
{
namespace Fitting {
template <typename T_p, size_t s_p,typename T_d>
class SimplexPoint :public Parameters<T_p,s_p>
{
public:
    template<class ... Args>
    SimplexPoint(Args ...args)
        :Parameters<T_p, s_p>(args...), m_error(0),m_model(nullptr) {};
    SimplexPoint(std::array<T_p, s_p> parameters)
        :Parameters<T_p, s_p>(parameters),m_error(0),m_model(nullptr) {};
    void setToBounds(const Bounds<T_p,s_p> minBounds, const Bounds<T_p,s_p> maxBounds) 
    {
        setToMinBounds(minBounds);
        setToMaxBounds(maxBounds);
    }

    /*
    template<typename T_d>
    double calculateError(const std::vector<T_d>& motherCharacteristic, 
                            std::vector<T_d> arguments)
    {
        double error=0.0;
        std::vector<T_d> calculatedData = calculateData(arguments);
        for (int i = 0; i < motherCharacteristic.size(); i++)
        {
            calculatedData[i] -= motherCharacteristic[i];
            calculatedData[i] *= calculatedData[i];
        }
        return std::accumulate(calculatedData.begin(), calculatedData.end(), 0);

    };
    template <typename T_d>
    std::vector<T_d> calculateData(std::vector<T_d> arguments) 
    {
        return m_model(this->m_parameters, arguments);
    }
     */
    
    using DataModel = std::vector<T_d>(*)(Parameters<T_p, s_p> param, std::vector<T_d>& args);
private:
    double m_error;
    
    DataModel m_model;
public:
    
    void setModel(DataModel modelToSet) {m_model = modelToSet;}
private:
    void setToMinBounds(const Bounds<T_p,s_p> minBounds) 
    {
    for (int i = 0; i < s_p; i++)
        if (this->m_parameters[i] < minBounds[i])
            this->m_parameters[i] = minBounds[i];
    }
    void setToMaxBounds(const Bounds<T_p,s_p> maxBounds) 
    {
    for (int i = 0; i < s_p; i++)
        if (this->m_parameters[i] > maxBounds[i])
            this->m_parameters[i] = maxBounds[i];
    }
};
}
}

