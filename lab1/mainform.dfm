object fMain: TfMain
  Left = 197
  Top = 115
  BorderStyle = bsSingle
  Caption = #1052#1086#1085#1090#1077'-'#1050#1072#1088#1083#1086
  ClientHeight = 451
  ClientWidth = 330
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 13
  object lCirclex: TLabel
    Left = 8
    Top = 24
    Width = 174
    Height = 13
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1072' X '#1094#1077#1085#1090#1088#1072' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1080':'
  end
  object lCircley: TLabel
    Left = 8
    Top = 56
    Width = 174
    Height = 13
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1072' Y '#1094#1077#1085#1090#1088#1072' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1080':'
  end
  object lRadius: TLabel
    Left = 8
    Top = 88
    Width = 102
    Height = 13
    Caption = #1056#1072#1076#1080#1091#1089' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1080':'
  end
  object lPrecision: TLabel
    Left = 8
    Top = 120
    Width = 50
    Height = 13
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100':'
  end
  object eCirclex: TEdit
    Left = 192
    Top = 16
    Width = 65
    Height = 21
    TabOrder = 0
  end
  object eCircley: TEdit
    Left = 192
    Top = 48
    Width = 65
    Height = 21
    TabOrder = 1
  end
  object eRadius: TEdit
    Left = 192
    Top = 80
    Width = 65
    Height = 21
    TabOrder = 2
  end
  object pcMain: TPageControl
    Left = 8
    Top = 144
    Width = 313
    Height = 305
    ActivePage = TabSheet1
    TabOrder = 3
    object TabSheet1: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1088#1072#1089#1095#1105#1090#1072
      object lReal: TLabel
        Left = 8
        Top = 256
        Width = 3
        Height = 13
      end
      object sgResult: TStringGrid
        Left = 8
        Top = 40
        Width = 289
        Height = 217
        DefaultColWidth = 45
        TabOrder = 0
      end
      object bCalculate: TButton
        Left = 8
        Top = 8
        Width = 289
        Height = 33
        Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
        TabOrder = 1
        OnClick = bCalculateClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1087#1088#1086#1075#1086#1085#1086#1074
      ImageIndex = 1
      object lStoppoints: TLabel
        Left = 8
        Top = 16
        Width = 173
        Height = 13
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1072' '#1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1074' '#1087#1088#1086#1075#1086#1085#1077':'
      end
      object lMaxpoints: TLabel
        Left = 8
        Top = 40
        Width = 199
        Height = 13
        Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1080#1089#1087#1099#1090#1072#1085#1080#1081':'
      end
      object lCurrentpoints: TLabel
        Left = 8
        Top = 64
        Width = 167
        Height = 13
        Caption = #1059#1082#1072#1078#1080#1090#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1072' '#1080#1089#1087#1099#1090#1072#1085#1080#1081':'
      end
      object lCount: TLabel
        Left = 8
        Top = 136
        Width = 85
        Height = 13
        Caption = #1063#1080#1089#1083#1086' '#1087#1088#1086#1075#1086#1085#1086#1074':'
      end
      object eStoppoints: TEdit
        Left = 248
        Top = 8
        Width = 33
        Height = 21
        ReadOnly = True
        TabOrder = 0
        Text = '4'
      end
      object udStoppoints: TUpDown
        Left = 281
        Top = 8
        Width = 16
        Height = 21
        Associate = eStoppoints
        Min = 1
        Max = 6
        Position = 4
        TabOrder = 1
        OnClick = udStoppointsClick
      end
      object eMaxpoints: TEdit
        Left = 208
        Top = 32
        Width = 89
        Height = 21
        TabOrder = 2
        Text = '10000'
        OnChange = eMaxpointsChange
      end
      object sgCurrentpoints: TStringGrid
        Left = 8
        Top = 88
        Width = 289
        Height = 49
        BorderStyle = bsNone
        Color = clBtnFace
        ColCount = 4
        DefaultColWidth = 45
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 3
        OnExit = sgCurrentpointsExit
      end
      object eCount: TEdit
        Left = 96
        Top = 128
        Width = 33
        Height = 21
        ReadOnly = True
        TabOrder = 4
        Text = '5'
      end
      object udCount: TUpDown
        Left = 129
        Top = 128
        Width = 16
        Height = 21
        Associate = eCount
        Min = 1
        Max = 10
        Position = 5
        TabOrder = 5
        OnClick = udCountClick
      end
    end
  end
  object ePrecision: TEdit
    Left = 192
    Top = 112
    Width = 65
    Height = 21
    ReadOnly = True
    TabOrder = 4
    Text = '1'
  end
  object udPrecision: TUpDown
    Left = 257
    Top = 112
    Width = 16
    Height = 21
    Associate = ePrecision
    Min = 1
    Max = 9
    Position = 1
    TabOrder = 5
  end
end
