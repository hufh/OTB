/*
 * Copyright (C) 1999-2011 Insight Software Consortium
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



//  Software Guide : BeginLatex
//
//  This example illustrates how to read and write an image of pixel type
//  \code{std::complex}. The complex type is defined as an integral part of the
//  C++ language.
//
//  We start by including the headers of the complex class, the image, and the
//  reader and writer classes.
//
//  \index{otb::ImageFileRead!Complex images}
//  \index{otb::ImageFileWrite!Complex images}
//  \index{Complex images!Instantiation}
//  \index{Complex images!Reading}
//  \index{Complex images!Writing}
//
//  Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
#include <complex>
#include "otbImage.h"
#include "otbImageFileReader.h"
#include "otbImageFileWriter.h"
// Software Guide : EndCodeSnippet

int main(int argc, char * argv[])
{

  // Verify the number of parameters in the command line
  if (argc < 3)
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " inputImageFile  outputImageFile " << std::endl;
    return EXIT_FAILURE;
    }

// Software Guide : BeginLatex
//
// The image dimension and pixel type must be declared. In this case we use the
// \code{std::complex<>} as the pixel type. Using the dimension and pixel type
// we proceed to instantiate the image type.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
  const unsigned int Dimension = 2;

  typedef std::complex<float>              PixelType;
  typedef otb::Image<PixelType, Dimension> ImageType;
// Software Guide : EndCodeSnippet

// Software Guide : BeginLatex
//
// The image file reader and writer types are instantiated using the image
// type. We can then create objects for both of them.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
  typedef otb::ImageFileReader<ImageType> ReaderType;
  typedef otb::ImageFileWriter<ImageType> WriterType;

  ReaderType::Pointer reader = ReaderType::New();
  WriterType::Pointer writer = WriterType::New();
// Software Guide : EndCodeSnippet

// Software Guide : BeginLatex
//
// Filenames should be provided for both the reader and the writer. In this
// particular example we take those filenames from the command line arguments.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
  reader->SetFileName(argv[1]);
  writer->SetFileName(argv[2]);
// Software Guide : EndCodeSnippet

// Software Guide : BeginLatex
//
// Here we simply connect the output of the reader as input to the writer.
// This simple program could be used for converting complex images from one
// fileformat to another.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
  writer->SetInput(reader->GetOutput());
// Software Guide : EndCodeSnippet

// Software Guide : BeginLatex
//
// The execution of this short pipeline is triggered by invoking the Update()
// method of the writer. This invocation must be placed inside a try/catch
// block since its execution may result in exceptions being thrown.
//
// Software Guide : EndLatex

// Software Guide : BeginCodeSnippet
  try
    {
    writer->Update();
    }
  catch (itk::ExceptionObject& err)
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
    }
// Software Guide : EndCodeSnippet

// Software Guide : BeginLatex
//
// For a more interesting use of this code, you may want to add a filter in
// between the reader and the writer and perform any complex image to complex
// image operation.
//
// Software Guide : EndLatex

  return EXIT_SUCCESS;
}
