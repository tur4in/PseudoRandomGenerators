﻿// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneratorCreator.h"
#include <iostream>
#include "ITestBase.h"
#include "UniformityTest.h"
#include "XLSResultWriter.h"

int main()
{
    CGeneratorCreator generatorCreator;
    auto generator = generatorCreator.CreateGenerator(CGeneratorCreator::Librarian,lint(100));
    std::unique_ptr<ITestBase> test = std::make_unique<СUniformityTest>(generator);
    auto testResults = test->ExecuteTesting(1000000);
    std::cout << testResults.m_testName << std::endl;
    std::cout << testResults.m_generatorName<< std::endl;
    std::cout << testResults.m_length<< std::endl;
    for(int i=0;i<3;++i)
    {
        std::cout << testResults.m_results[i].m_KhiCryteriaPractical << std::endl;
        std::cout << testResults.m_results[i].m_KhiCryteriaTheory << std::endl;
        std::cout << testResults.m_results[i].m_alpha<< std::endl;
        std::cout << testResults.m_results[i].m_isAcceptable<< std::endl;
    }

    CXLSResultWriter writer("tmp.xls");
    writer.WriteResults(testResults);
    std::cin.get();
    std::cin.get();

    return 0;
}

