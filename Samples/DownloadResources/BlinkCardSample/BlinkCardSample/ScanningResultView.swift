// Created by Toni Krešo on 20.3.2025.. 
// Copyright (c) 2025 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION 
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS, 
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING 
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED! 
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT 
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import BlinkCard

struct ScanningResultView : View {
    @EnvironmentObject private var viewModel: BlinkCardViewModel
    private let scanningResult: BlinkCardScanningResult

    init(scanningResult: BlinkCardScanningResult) {
        self.scanningResult = scanningResult
    }

    var body: some View {
        List {
            if let firstFrame = scanningResult.firstSideResult?.cardImage,
               let uiImage = firstFrame.uiImage {
                Text("First camera frame:")
                Image(uiImage: uiImage)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            }
            if let secondFrame = scanningResult.secondSideResult?.cardImage,
               let uiImage = secondFrame.uiImage  {
                Text("Second camera frame:")
                Image(uiImage: uiImage)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            }

            if let cardholderName = scanningResult.cardholderName {
                Text("Cardholder name: \(cardholderName)")
            }
            if let iban = scanningResult.iban {
                Text("IBAN: \(iban)")
            }
            
            Text("Issuing network: \(scanningResult.issuingNetwork)")
            
            Button("Cancel") {
                viewModel.state = .home
            }
        }
    }
}
