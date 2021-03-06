// The MIT License (MIT)
//
// Copyright (c) 2013 Voxer
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#import <Foundation/Foundation.h>
#import "ispdy.h"  // ISpdyVersion

typedef enum {
  kISpdyCompressorModeDictDeflate,
  kISpdyCompressorModeDeflate,
  kISpdyCompressorModeGzip
} ISpdyCompressorMode;

// Wrapper class for deflating/inflating data using zlib with SPDY dictionary
@interface ISpdyCompressor : NSObject

// Initialize compressor with specific protocol version
- (id) init: (ISpdyVersion) version;

// Initialize compressor with specific protocol version and mode
- (id) init: (ISpdyVersion) version withMode: (ISpdyCompressorMode) mode;

// Get last operation's output
- (NSMutableData*) output;

// Get last operation's error
- (NSError*) error;

// Deflate input data
- (BOOL) deflate: (NSData*) input;

// Inflate input data
- (BOOL) inflate: (NSData*) input;

// (Internal) use deflate()/inflate() instead
- (BOOL) process: (BOOL) isDeflate in: (NSData*) input;

@end
