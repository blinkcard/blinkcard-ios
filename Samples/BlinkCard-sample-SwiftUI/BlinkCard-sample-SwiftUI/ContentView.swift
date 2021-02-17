// Created by Jura Skrlec on 17.02.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

import SwiftUI
import BlinkCard

struct ContentView: View {
    @State private var showingBlinkCardViewController = false
    @State private var showBlinkCardResult = false
    @State private var blinkCardRecognizer: MBCBlinkCardRecognizer = MBCBlinkCardRecognizer()
    var body: some View {
        VStack {
            Button("Scan") {
                self.showingBlinkCardViewController = true
            }
        }
        .fullScreenCover(isPresented: $showingBlinkCardViewController) {
            BlinkCardViewController(showAlert: $showBlinkCardResult, blinkCardRecognizer: $blinkCardRecognizer)
                .alert(isPresented: $showBlinkCardResult) { () -> Alert in
                    let alert = Alert(title: Text("BlinkCard Results"),
                                      message: Text(self.blinkCardRecognizer.result.description),
                                      dismissButton: .default(Text("Ok"),
                                      action: {
                        self.showingBlinkCardViewController.toggle()
                    }))
                    return alert
                }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
