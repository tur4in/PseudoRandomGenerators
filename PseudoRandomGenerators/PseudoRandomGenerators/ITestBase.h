#pragma once
#include <string>
#include <memory>
#include "IGeneratorBase.h"
#include <vector>

class IGeneratorBase;

struct AlphaTestResult
{
    float m_alpha;
    bool m_isAcceptable;
    double m_KhiCryteriaTheory;
    double m_KhiCryteriaPractical;
};

struct TestResult
{
    std::string m_generatorName;
    std::wstring m_testName;
    unsigned int m_length;
    AlphaTestResult m_results[3];
};


class ITestBase
{
public:
    enum TestMode
    {
        FileSourceMode,
        GeneratorMode
    };

    explicit ITestBase(const std::string& filename):m_testMode(FileSourceMode),m_filename(filename){}
    explicit ITestBase(const std::shared_ptr<IGeneratorBase>& generator)
        :m_testMode(GeneratorMode),m_generator(generator){}
    virtual ~ITestBase()=default;
    virtual TestResult ExecuteTesting(int length)=0;
    void SetTestName(const std::string& name) { m_testName = name; }

    std::wstring GetTestName() const
    { return std::wstring(m_testName.begin(),m_testName.end()); }
protected:
    lint GetNextValue();
    std::string GetGeneratorName()const { return m_generator->GetName(); }
private:
    TestMode m_testMode;
    std::string m_testName;
    std::shared_ptr<IGeneratorBase> m_generator;
    std::string m_filename;
};
